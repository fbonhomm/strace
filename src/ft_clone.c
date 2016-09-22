/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 19:32:52 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/10/30 19:32:54 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strace.h"
#include "syscall_names_64.h"

void		ft_clone(t_strc *strc)
{
	if (strc->reg[1] == 0)
		fprintf(stderr, "child_stack=0, ");
	else
		fprintf(stderr, "child_stack=%p, ", (void*)strc->reg[1]);
	fprintf(stderr, "flags=%lu, ", (unsigned long)strc->reg[0]);
	fprintf(stderr, "child_tidptr=%p", (void*)strc->reg[3]);
}
