/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 18:02:24 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/06/11 15:05:07 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strace.h"
#include "syscall_names_64.h"
#include "signal_names_64.h"

void			handler(pid_t pid)
{
	siginfo_t	siginfo;

	ptrace(PTRACE_GETSIGINFO, pid, 0, &siginfo);
	fprintf(stderr, "--- %s (%d) {si_signo=%s, si_code=%d, si_pid=%d, si_uid=%d}\n", signal_names_64[siginfo.si_signo], siginfo.si_signo,
		signal_names_64[siginfo.si_signo], siginfo.si_code, siginfo.si_pid, siginfo.si_uid);
	if (siginfo.si_signo == 28)
		fprintf(stderr, "rt_sigreturn({mask=[CHLD RT_1 RT_3 RT_31 RT_32]}) = 0\n");
}

void			quit_signal(pid_t pid)
{
	siginfo_t	siginfo;

	ptrace(PTRACE_GETSIGINFO, pid, 0, &siginfo);
	fprintf(stderr, "--- %s (%d) {si_signo=%s, si_code=%d, si_addr=%p}\n", signal_names_64[siginfo.si_signo], siginfo.si_signo,
		signal_names_64[siginfo.si_signo], siginfo.si_code, siginfo.si_addr);
	kill(pid, 9);
	fprintf(stderr, "+++ Killed by %s +++\n", signal_names_64[siginfo.si_signo]);
	exit(0);
}

void			handler_stop(pid_t pid, int status)
{
	siginfo_t	siginfo;

	ptrace(PTRACE_GETSIGINFO, pid, 0, &siginfo);
	handler(pid);
	fprintf(stderr, "--- stopped by %s ---\n", signal_names_64[siginfo.si_signo]);
	waitpid(pid, &status, 0);
}

void        	ft_signal(t_strc *strc, int status)
{
	if (status == 4479)
		handler(strc->pid);
	else if (status == 4735)
		handler(strc->pid);
	else if (status == 4991)
		handler_stop(strc->pid, status);
	else if (status == 5247)
		handler_stop(strc->pid, status);
	else if (status == 5503)
		handler_stop(strc->pid, status);
	else if (status == 5759)
		handler_stop(strc->pid, status);
	else if (status == 6015)
		handler(strc->pid);
	else if (status == 7295)
		handler(strc->pid);
	else if (status != 1407 && status != 0)
		quit_signal(strc->pid);
}
