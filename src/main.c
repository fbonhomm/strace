/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 18:02:36 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/06/11 15:47:21 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strace.h"
#include "syscall_names_64.h"

int         	main(int ac, char **av, char **env)
{
    t_strc  	strc;
	char		*path;

    if (ac == 1)
		fprintf(stderr, " Usage : ft_strace [-c] [...]\n");
    else if (av[1] && ft_strcmp(av[1], "-c") == 0 && (!av[2]))
		fprintf(stderr, " Usage : ft_strace [-c] [...]\n");
    else
    {
        ft_init(&strc);
        ft_arg(&strc, av);
		path = ft_path(&strc, env);
        ft_check(&strc, av, env, path);
    }
    return (0);
}
