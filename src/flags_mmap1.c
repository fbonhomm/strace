/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 18:02:02 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/10/30 18:02:07 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strace.h"

void 		flags_mmap1(int flags)
{
	int		i;

	i = 0;
	if ((flags & PROT_EXEC) == PROT_EXEC)
	{
		if (i == 1)
			fprintf(stderr, "|");
		i = 1;
		fprintf(stderr, "PROT_EXEC");
	}
	if ((flags & PROT_READ) == PROT_READ)
	{
		if (i == 1)
			fprintf(stderr, "|");
		i = 1;
		fprintf(stderr, "PROT_READ");
	}
	if ((flags & PROT_WRITE) == PROT_WRITE)
	{
		if (i == 1)
			fprintf(stderr, "|");
		i = 1;
		fprintf(stderr, "PROT_WRITE");
	}
	if (flags == 0)
		fprintf(stderr, "PROT_NONE");
}
