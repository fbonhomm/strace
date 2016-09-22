/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigpro.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 19:32:52 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/06/11 16:46:47 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strace.h"
#include "syscall_names_64.h"
#include "signal_names_64.h"

void						sigpro(void)
{
	sigset_t			x;
	struct sigaction	act;
	int					i;

	i = 1;
	sigemptyset(&x);
	act.sa_handler = NULL;
	act.sa_flags = 0;
	act.sa_mask = x;
	while (i <= 32)
	{
		sigaction(i, &act, NULL);
		sigaddset(&x, i++);
	}
	sigprocmask(SIG_SETMASK, &x, NULL);
	sigprocmask(SIG_UNBLOCK, &x, NULL);
	sigemptyset(&x);
	sigaddset(&x, SIGHUP);
	sigaddset(&x, SIGINT);
	sigaddset(&x, SIGQUIT);
	sigaddset(&x, SIGPIPE);
	sigaddset(&x, SIGTERM);
	sigprocmask(SIG_BLOCK, &x, NULL);
}
