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

void		ft_mprotect(t_strc *strc)
{
	if (strc->reg[0] == 0)
		fprintf(stderr, "NULL");
	else
		fprintf(stderr, "%p, ", (void*)strc->reg[0]);
	fprintf(stderr, "%zu, ", (size_t)strc->reg[1]);
	flags_mmap1((int)strc->reg[2]);
}
