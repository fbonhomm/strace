/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 19:32:52 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/06/09 06:23:58 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strace.h"
#include "syscall_names_64.h"

void		ft_open(t_strc *strc)
{
	char	*str;

	str = getdata(strc->pid, strc->reg[0], 0);
	print_strace(str);
	str = ft_free(str);
	fprintf(stderr, ", ");
	flags_open((int)strc->reg[1]);
}
