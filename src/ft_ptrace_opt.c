/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrace_opt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 19:32:52 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/06/11 16:51:42 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strace.h"
#include "syscall_names_64.h"
#include "signal_names_64.h"

int        		signal_opt(t_strc *strc, int status)
{
	if (status == 4479)
		;
	else if (status == 4735)
		;
	else if (status == 4991)
		waitpid(strc->pid, &status, 0);
	else if (status == 5247)
		waitpid(strc->pid, &status, 0);
	else if (status == 5503)
		waitpid(strc->pid, &status, 0);
	else if (status == 5759)
		waitpid(strc->pid, &status, 0);
	else if (status == 6015)
		;
	else if (status == 7295)
		;
	else if (status != 1407 && status != 0)
	{
		kill(strc->pid, 9);
		return (0);
	}
	return (1);
}

int				end(struct user_regs_struct *regs, t_strc *strc)
{
	if (ft_strcmp(syscall_names_64[strc->syscall][1], "str") == 0)
	{
		if ((int)(regs->rax) < 0)
			return (0);
		else
			return (1);
	}
	else if (ft_strcmp(syscall_names_64[strc->syscall][1], "ptr") == 0)
	{
		if (((long long int)regs->rax) < 0)
			return (0);
		else
			return (1);
	}
	else if (ft_strcmp(syscall_names_64[strc->syscall][1], "int") == 0)
	{
		if ((int)(regs->rax) < 0)
			return (0);
		else
			return (1);
	}
	else if (ft_strcmp(syscall_names_64[strc->syscall][1], "uint") == 0)
	{
		if ((long)(regs->rax) < 0)
			return (0);
		else
			return (1);
	}
	else if (ft_strcmp(syscall_names_64[strc->syscall][1], "long") == 0)
	{
		if (((long)regs->rax) < 0)
			return (0);
		else
			return (1);
	}
	else if (ft_strcmp(syscall_names_64[strc->syscall][1], "ulong") == 0)
	{
		if (((long long int)regs->rax) < 0)
			return (0);
		else
			return (1);
	}
	else
	{
		if (((long long int)regs->rax) < 0)
			return (0);
		else
			return (1);
	}
}


void                        ft_ptrace_opt(t_strc *strc)
{
	int                     status;
	int						i;
	double					tab[320][3];
	struct user_regs_struct regs;
	clock_t					st;
	clock_t					en;

	status = 0;
	i = -1;
	ptrace(PTRACE_SEIZE, strc->pid, NULL, NULL);
	waitpid(strc->pid, &status, 0);
	while (++i < 320)
	{
		tab[i][0] = 0;
		tab[i][1] = 0;
		tab[i][2] = 0.000000;
	}
	sigpro();
	while (42)
	{
		st = clock();
		ptrace(PTRACE_SYSCALL, strc->pid, 0, 0);
		waitpid(strc->pid, &status, 0);
		if ((status == 1407) || (status == 0))
		{
			ptrace(PTRACE_SYSCALL, strc->pid, 0, 0);
			waitpid(strc->pid, &status, 0);
			en = clock();
			ptrace(PTRACE_GETREGS, strc->pid, 0, &regs);
			strc->syscall = regs.orig_rax;
			if (strc->syscall != 231)
			{
				if (!(end(&regs, strc)))
					tab[strc->syscall][0]++;
				tab[strc->syscall][1]++;
				tab[strc->syscall][2] += ((double)(en - st) / CLOCKS_PER_SEC);
			}
		}
		if (status == 7295)
		{
			en = clock();
			tab[15][1]++;
			tab[15][2] += ((double)(en - st) / CLOCKS_PER_SEC);
		}
		if ((!signal_opt(strc, status)))
			break;
		if(WIFEXITED(status))
		{
			if (!(end(&regs, strc)))
				tab[strc->syscall][0]--;
			tab[strc->syscall][1]--;
			tab[strc->syscall][2] -= ((double)(en - st) / CLOCKS_PER_SEC);
			break ;
		}
	}
	print_opt(tab);
}
