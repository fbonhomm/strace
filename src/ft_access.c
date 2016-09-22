/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_access.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 19:32:52 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/06/09 06:54:10 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strace.h"
#include "syscall_names_64.h"

void		flags_access(int flags)
{
	if (flags == R_OK)
		fprintf(stderr, "R_OK");
	if (flags == W_OK)
		fprintf(stderr, "W_OK");
	if (flags == F_OK)
		fprintf(stderr, "F_OK");
}

void		ft_access(t_strc *strc)
{
	char	*str;

	str = getdata(strc->pid, strc->reg[0], 0);
	print_strace(str);
	str = ft_free(str);
	fprintf(stderr, ", ");
	flags_access((int)strc->reg[1]);
}
