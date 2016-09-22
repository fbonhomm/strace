/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 18:02:12 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/10/30 18:02:15 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strace.h"

void        ft_init(t_strc *strc)
{
	int		sign[SIG] = {SIGHUP, SIGINT, SIGQUIT, SIGPIPE, SIGTERM};

    strc->tab = NULL;
    strc->env = NULL;
    strc->path = NULL;
    strc->exe = NULL;
    strc->pwd = NULL;
    strc->com = NULL;
    strc->name_sys = NULL;
	strc->sig = sign;

    strc->name = 0;
    strc->ret = 1;
    strc->nbr_arg = 2;
    strc->arg_1 = 3;
    strc->arg_2 = 4;
    strc->arg_3 = 5;
    strc->arg_4 = 6;
    strc->arg_5 = 7;
    strc->arg_6 = 8;
}
