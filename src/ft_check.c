/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 18:02:24 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/06/11 15:16:34 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strace.h"

void        			ft_check(t_strc *strc, char **av, char **env, char *path)
{
	sigset_t			x;

	sigemptyset(&x);
	sigprocmask(SIG_SETMASK, &x, NULL);
	sigemptyset(&x);
	sigaddset(&x, SIGTRAP);
	sigprocmask(SIG_BLOCK, &x, NULL);
    strc->pid = fork();
    if(strc->pid == 0)
	{
        execve(path, strc->tab, env);
		fprintf(stderr, "ft_strace: exec: %s\n", strerror(errno));
		exit(0);
	}
    else
    {
        kill(strc->pid, SIGSTOP);
        if (av[1] && ft_strcmp(av[1], "-c") == 0)
            ft_ptrace_opt(strc);
        else
            ft_ptrace(strc);
    }
}
