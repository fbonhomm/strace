/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 19:32:52 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/06/09 06:21:33 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strace.h"
#include "syscall_names_64.h"

char				*getdata_read(pid_t child, long addr, long rax)
{
	char			*val;
	int				read;
	long			allocated;
	long			tmp;

	val = (char*)malloc(sizeof(char) * 4096);
	allocated = 4096;
	read = 0;
	while (read <= rax)
	{
		if (read + ((long)sizeof(tmp)) > allocated)
		{
		   allocated *= 2;
		   val = realloc(val, allocated);
	   	}
	   	tmp = ptrace(PTRACE_PEEKDATA, child, addr + read);
	   	if(errno != 0 || tmp == -1)
            val[read] = 0;
		memcpy(val + read, &tmp, (sizeof(tmp)));
		read += (sizeof(tmp));
	}
	return (val);
}

void		print_read(char *str, long rax)
{
	int		i;

	i = 0;
	fprintf(stderr, "\"");
	while (i < rax)
	{
		if (ft_isprint(str[i]))
			fprintf(stderr, "%c", str[i]);
		else if (str[i] == '\n')
			fprintf(stderr, "\\n");
		else if (str[i] == '\t')
			fprintf(stderr, "\\t");
		else if (ft_isascii(str[i]))
			fprintf(stderr, "\\%o", str[i]);
		i++;
		if (i > 34)
			break ;
	}
	fprintf(stderr, "\"");
	if (i >= 34)
		fprintf(stderr, "...");
}

void		ft_read(struct user_regs_struct *regs, t_strc *strc)
{

	char	*str;

	fprintf(stderr, "%d, ", (int)strc->reg[0]);
	str = getdata_read(strc->pid, strc->reg[1], regs->rax);
	print_read(str, regs->rax);
	str = ft_free(str);
	fprintf(stderr, ", %u", (unsigned int)strc->reg[2]);
}
