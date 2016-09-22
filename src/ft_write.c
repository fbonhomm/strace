/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 19:32:52 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/06/09 06:24:43 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strace.h"
#include "syscall_names_64.h"

void				print_write(char *str, unsigned long len)
{
	unsigned long	i;

	i = 0;
	fprintf(stderr, "\"");
	while ((str[i]) && (i < len))
	{
		if (ft_isprint(str[i]))
			fprintf(stderr, "%c", str[i]);
		else if (str[i] == '\n')
			fprintf(stderr, "\\n");
		else if (str[i] == '\t')
			fprintf(stderr, "\\t");
		else if (ft_isascii(str[i]))
			fprintf(stderr, "\\%o", str[i]);
		else
			break ;
		i++;
		if (str[i] && i >= 34)
			break ;
	}
	fprintf(stderr, "\"");
	if (i >= 34)
		fprintf(stderr, "...");
}

void			ft_write(t_strc *strc)
{
	char		*str;

	fprintf(stderr, "%d, ", (int)strc->reg[0]);
	str = getdata(strc->pid, strc->reg[1], 0);
	print_write(str, strc->reg[2]);
	str = ft_free(str);
	fprintf(stderr, ", %u", (unsigned int)strc->reg[2]);
}
