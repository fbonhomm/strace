/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 19:32:52 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/06/10 18:19:41 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strace.h"
#include "syscall_names_64.h"
#include "signal_names_64.h"

void                        print_end(struct user_regs_struct *regs, t_strc *strc)
{
	char					*str;

	if (strc->syscall == 0)
		ft_read(regs, strc);
	fprintf(stderr, ") = ");
	if (ft_strcmp(syscall_names_64[strc->syscall][0], "exit_group") == 0)
		fprintf(stderr, "?\n");
	else if (ft_strcmp(syscall_names_64[strc->syscall][1], "str") == 0)
	{
		if ((int)(regs->rax) < 0)
			error(regs->rax);
		else
		{
			str = getdata(strc->pid, regs->rax, 0);
			print_strace(str);
			fprintf(stderr, "\n");
			str = ft_free(str);
		}
	}
	else if (ft_strcmp(syscall_names_64[strc->syscall][1], "ptr") == 0)
	{
		if ((long long int)(regs->rax) < 0)
			error(regs->rax);
		else if (regs->rax == 0)
			fprintf(stderr, "NULL\n");
		else
			fprintf(stderr, "%p\n", (void*)regs->rax);
	}
	else if (ft_strcmp(syscall_names_64[strc->syscall][1], "int") == 0)
	{
		if (((int)regs->rax) < 0)
			error(regs->rax);
		else
			fprintf(stderr, "%d\n", (int)regs->rax);
	}
	else if (ft_strcmp(syscall_names_64[strc->syscall][1], "uint") == 0)
	{
		if ((long)(regs->rax) < 0)
			error(regs->rax);
		else
			fprintf(stderr, "%u\n", (unsigned int)regs->rax);
	}
	else if (ft_strcmp(syscall_names_64[strc->syscall][1], "long") == 0)
	{
		if (((long)regs->rax) < 0)
			error(regs->rax);
		else
			fprintf(stderr, "%ld\n", (long)regs->rax);
	}
	else if (ft_strcmp(syscall_names_64[strc->syscall][1], "ulong") == 0)
	{
		if (((long long int)regs->rax) < 0)
			error(regs->rax);
		else
			fprintf(stderr, "%lu", (unsigned long)regs->rax);
	}
	else
	{
		if (((long long int)regs->rax) < 0)
			error(regs->rax);
		else
			fprintf(stderr, "%llu\n", regs->rax);
	}
}
