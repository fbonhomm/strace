/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syscall_names_64.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 22:49:24 by avasseur          #+#    #+#             */
/*   Updated: 2016/04/26 13:58:39 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_NAMES_64_H
# define SIGNAL_NAMES_64_H

static const char     signal_names_64[66][20] =
{
	{"unknown"},
	{"SIGHUP"},
	{"SIGINT"},
	{"SIGQUIT"},
	{"SIGILL"},
	{"SIGTRAP"},
	{"SIGABRT"},
	{"SIGBUS"},
	{"SIGFPE"},
	{"SIGKILL"},
	{"SIGUSR1"},
	{"SIGSEGV"},
	{"SIGUSR2"},
	{"SIGPIPE"},
	{"SIGALRM"},
	{"SIGTERM"},
	{"SIGSTKFLT"},
	{"SIGCHLD"},
	{"SIGCONT"},
	{"SIGSTOP"},
	{"SIGTSTP"},
	{"SIGTTIN"},
	{"SIGTTOU"},
	{"SIGURG"},
	{"SIGXCPU"},
	{"SIGXFSZ"},
	{"SIGVTALRM"},
	{"SIGPROF"},
	{"SIGWINCH"},
	{"SIGIO"},
	{"SIGPWR"},
	{"SIGSYS"},
	{"unknown"},
	{"unknown"},
	{"SIGRTMIN"},
};
#endif
