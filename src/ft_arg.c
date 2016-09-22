/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 18:02:02 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/06/11 15:41:20 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strace.h"

void        ft_arg(t_strc *strc, char **av)
{
    int     i;
    int     x;

    x = 0;
    i = 0;
    while(av[i])
        i++;
    strc->tab = (char**)malloc(sizeof(char*) * (i + 1));
    if (av[1] && ft_strcmp(av[1], "-c") == 0)
        i = 2;
    else
        i = 1;
    while(av[i])
        strc->tab[x++] = ft_strdup(av[i++]);
    strc->tab[x] = NULL;
}
