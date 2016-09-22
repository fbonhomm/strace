/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 19:32:52 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/06/11 14:59:27 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strace.h"
#include "syscall_names_64.h"
#include "signal_names_64.h"

void                        ft_attrib(struct user_regs_struct *regs, t_strc *strc)
{
	memset(strc->reg, 0, sizeof(strc->reg));
    strc->reg[0] = regs->rdi;
    strc->reg[1] = regs->rsi;
    strc->reg[2] = regs->rdx;
    strc->reg[3] = regs->rcx;
    strc->reg[4] = regs->r8;
    strc->reg[5] = regs->r9;
	strc->reg[6] = 0;
	strc->nbr_arg = ft_atoi(syscall_names_64[regs->orig_rax][2]);
	strc->syscall = regs->orig_rax;
}

void                        ft_ptrace(t_strc *strc)
{
    int                     status;
	unsigned long			i;
    struct user_regs_struct regs;

    status = 0;
    ptrace(PTRACE_SEIZE, strc->pid, NULL, NULL);
	waitpid(strc->pid, &status, 0);
	sigpro();
	i = 0;
    while (42)
    {
		ptrace(PTRACE_SYSCALL, strc->pid, 0, 0);
		waitpid(strc->pid, &status, 0);
		if ((status == 1407) || (status == 0))
		{
	        ptrace(PTRACE_GETREGS, strc->pid, 0, &regs);
	        ft_attrib(&regs, strc);
			print_start(strc);
			ptrace(PTRACE_SYSCALL, strc->pid, 0, 0);
			waitpid(strc->pid, &status, 0);
			ptrace(PTRACE_GETREGS, strc->pid, 0, &regs);
			print_end(&regs, strc);
		}
		else
			ft_signal(strc, status);
		if(WIFEXITED(status))
		{
			fprintf(stderr, "+++ exited with %d +++\n", (int)regs.rdi);
			break ;
		}
		i++;
    }
}
