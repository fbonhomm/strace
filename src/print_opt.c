/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_opt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 19:32:52 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/06/10 18:14:24 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strace.h"
#include "syscall_names_64.h"
#include "signal_names_64.h"

void			print_opt(double tab[320][3])
{
	int			call;
	int			error;
	double		sec;
	double		tmp;
	int			i;

	i = 0;
	call = 0;
	error = 0;
	while (i < 320)
	{
		if (tab[i][1] != 0)
			sec += tab[i][2];
		i++;
	}
	i = 0;
	fprintf(stderr, "time     seconds     usecs/call  calls       errors      syscall\n");
	fprintf(stderr, "------   ----------  ----------  ----------  ----------  ------------------\n");
	while (i < 320)
	{
		if (tab[i][1] != 0)
		{
			if ((tmp = (tab[i][2] * 100 / sec)) < 10)
				fprintf(stderr, "00%.2lf", tmp);
			else if (tmp < 100)
				fprintf(stderr, "0%.2lf", tmp);
			else
				fprintf(stderr, "%.2lf", tmp);
			fprintf(stderr, "   %f    0\t\t %d\t     %d\t\t %s\n", tab[i][2], (int)tab[i][1], (int)tab[i][0], syscall_names_64[i][0]);
			error += (int)tab[i][0];
			call += (int)tab[i][1];
		}
		i++;
	}
	fprintf(stderr, "------   ----------  ----------  ----------  ----------  ------------------\n");
	fprintf(stderr, "100.00   %f                %d          %d           total\n", sec, call, error);
}
