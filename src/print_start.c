/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 19:32:52 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/06/09 06:48:38 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strace.h"
#include "syscall_names_64.h"
#include "signal_names_64.h"

int			ft_count(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void		other_print_start(t_strc *strc)
{
	int                     i;
	int                     count;
	char					*str;
	char					**tab;

	i = 3;
	count = 0;
	while (count < strc->nbr_arg && count <= 6)
    {
		if (count != 0)
			fprintf(stderr, ", ");
		if ((ft_strcmp(syscall_names_64[strc->syscall][i], "str") == 0))
		{
			str = getdata(strc->pid, strc->reg[count], 0);
			print_strace(str);
			str = ft_free(str);
		}
		else if ((ft_strcmp(syscall_names_64[strc->syscall][i], "array") == 0))
		{
			tab = getdata_array(strc->pid, strc->reg[count]);
			if (count == 2)
				fprintf(stderr, "[/* %d vars */]", ft_count(tab));
			else
				print_strace_array(tab);
			tab = ft_free_array(tab);
		}
		else if (ft_strcmp(syscall_names_64[strc->syscall][i], "ptr") == 0)
		{
			if (strc->reg[count] == 0)
				fprintf(stderr, "NULL");
			else
				fprintf(stderr, "%p", (void*)strc->reg[count]);
		}
		else if (ft_strcmp(syscall_names_64[strc->syscall][i], "int") == 0)
			fprintf(stderr, "%d", (int)strc->reg[count]);
		else if (ft_strcmp(syscall_names_64[strc->syscall][i], "uint") == 0)
			fprintf(stderr, "%u", (unsigned int)strc->reg[count]);
		else if (ft_strcmp(syscall_names_64[strc->syscall][i], "long") == 0)
			fprintf(stderr, "%ld", (long)strc->reg[count]);
		else
        	fprintf(stderr, "%lu", strc->reg[count]);
		count++;
        i++;
    }
}

void                        print_start(t_strc *strc)
{
	if (strc->syscall <= 314 && strc->syscall >= 0)
		fprintf(stderr, "%s(", syscall_names_64[strc->syscall][0]);
	if (strc->syscall == 0)
		return ;
	else if (strc->syscall == 1)
		ft_write(strc);
	else if (strc->syscall == 2)
		ft_open(strc);
	else if (strc->syscall == 9)
		ft_mmap(strc);
	else if (strc->syscall == 10)
		ft_mprotect(strc);
	else if (strc->syscall == 21)
		ft_access(strc);
	else if (strc->syscall == 56)
		ft_clone(strc);
	else
		other_print_start(strc);

}
