/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strace.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 18:06:19 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/06/10 17:13:48 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRACE_H
# define FT_STRACE_H

# include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/user.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/mman.h>

#define	SIG 5

typedef struct          	s_strc
{
    char                	**tab;
    char                	**env;
    char                	**path;
    char                	**name_sys;
    char					*exev;
    char					*exe;
    char                	*pwd;
    char                	*com;
	int						*sig;
    int                 	name;
    int                 	ret;
    int                 	nbr_arg;
    int                 	arg_1;
    int                 	arg_2;
    int                 	arg_3;
    int                 	arg_4;
    int                 	arg_5;
    int                 	arg_6;
    int                 	syscall;
    char                	**syscall_nbr;
    long                	params[3];
    unsigned long int		reg[7];
	struct sigaction		act;
    pid_t               	pid;
}                       	t_strc;

typedef struct				s_lst
{
	char					syscall[50];
	int						call;
	int						error;
}							t_lst;

void        ft_arg(t_strc *strc, char **av);
void        ft_check(t_strc *strc, char **av, char **env, char *path);
void        ft_init(t_strc *strc);
char        *ft_path(t_strc *strc, char **env);
void        ft_ptrace(t_strc *strc);
void        ft_ptrace_opt(t_strc *strc);
char		*getdata(pid_t child, unsigned long addr, long read);
char		**getdata_array(pid_t pid, long addr);
void		print_strace_array(char **tab);
void		print_strace(char *str);
void		ft_open(t_strc *strc);
void		ft_read(struct user_regs_struct *regs, t_strc *strc);
void 		flags_open(int flags);
void 		flags_mmap1(int flags);
void 		flags_mmap2(int flags);
void		ft_mmap(t_strc *strc);
void		ft_mprotect(t_strc *strc);
void		ft_access(t_strc *strc);
void		ft_write(t_strc *strc);
void		ft_clone(t_strc *strc);
void        ft_signal(t_strc *strc, int status);
void		ft_handler(int sig);
void		error(long long int rax);
void		print_end(struct user_regs_struct *regs, t_strc *strc);
void		print_start(t_strc *strc);
void		sigpro(void);
void		print_opt(double tab[320][3]);

#endif
