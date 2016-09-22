/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 19:32:52 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/06/09 06:52:19 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strace.h"
#include "syscall_names_64.h"

char				*getdata(pid_t child, unsigned long addr, long read)
{
	char			*val;
	long			allocated;
	long			tmp;

	val = (char*)malloc(sizeof(char) * 4096);
	allocated = 4096;
	while (42)
	{
		if ((read + ((long)sizeof(tmp))) > allocated)
		{
		   allocated *= 2;
		   val = realloc(val, allocated);
	   	}
	   	tmp = ptrace(PTRACE_PEEKDATA, child, addr + read);
	   	if(errno != 0 || tmp <= 0)
	   	{

            val[read] = 0;
			if (read == 0)
				val = NULL;
            break;
		}
		memcpy(val + read, &tmp, (sizeof(tmp)));
		if (memchr(&tmp, 0, (sizeof(tmp))) != NULL)
			break;
		read += (sizeof(tmp));
	}
	return (val);
}

char				**getdata_array(pid_t pid, long addr)
{
    long			data;
    char			**array;
    unsigned		i;
    int				next;

    array = (char **)malloc(sizeof(char *) * 256);
    i = 0;
	while (next)
    {
		data = ptrace(PTRACE_PEEKDATA, pid, addr + i * sizeof(long));
        array[i] = getdata(pid, data, 0);
        i++;
        next = (data != 0);
        next &= (i < 256);
    }
	array[i] = NULL;
    return (array);
}
