/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_strace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 19:32:52 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/06/11 15:51:57 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strace.h"
#include "syscall_names_64.h"

void		print_strace(char *str)
{
	int		i;

	i = 0;
	fprintf(stderr, "\"");
	while ((str[i]))
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

void		print_strace_array(char **tab)
{
	int		i;
	int		j;
	int		x;

	x = 0;
	i = 0;
	fprintf(stderr, "[");
	while (tab[i])
	{
		j = 0;
		if (i != 0)
			fprintf(stderr, ", ");
		fprintf(stderr, "\"");
		while (tab[i][j])
		{
			if (ft_isprint(tab[i][j]))
				fprintf(stderr, "%c", tab[i][j]);
			else if (tab[i][j] == '\n')
				fprintf(stderr, "\\n");
			else if (tab[i][j] == '\t')
				fprintf(stderr, "\\t");
			else
				fprintf(stderr, "%o", tab[i][j]);
			if (tab[i][j] && x >= 34)
				break ;
			x++;
			j++;
		}
		fprintf(stderr, "\"");
		i++;
	}
	if (x >= 34)
		fprintf(stderr, "...");
	fprintf(stderr, "]");
}
