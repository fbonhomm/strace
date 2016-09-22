/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 18:02:02 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/10/30 18:02:07 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strace.h"

void 		flags_open(int flags)
{
	int		i;

	i = 0;
	if ((flags & O_RDWR) == O_RDWR)
	{
		if (i == 1)
			fprintf(stderr, "|");
		i = 1;
		fprintf(stderr, "O_RDWR");
	}
	if ((flags & O_RDONLY) == O_RDONLY && i == 0)
	{
		if (i == 1)
			fprintf(stderr, "|");
		i = 1;
		fprintf(stderr, "O_RDONLY");
	}
	if ((flags & O_WRONLY) == O_WRONLY && i == 0)
	{
		if (i == 1)
			fprintf(stderr, "|");
		i = 1;
		fprintf(stderr, "O_WRONLY");
	}
	if ((flags & O_CREAT) == O_CREAT)
	{
		if (i == 1)
			fprintf(stderr, "|");
		i = 1;
		fprintf(stderr, "O_CREAT");
	}
	if ((flags & O_EXCL) == O_EXCL)
	{
		if (i == 1)
			fprintf(stderr, "|");
		i = 1;
		fprintf(stderr, "O_EXCL");
	}
	if ((flags & O_NOCTTY) == O_NOCTTY)
	{
		if (i == 1)
			fprintf(stderr, "|");
		i = 1;
		fprintf(stderr, "O_NOCTTY");
	}
	if ((flags & O_APPEND) == O_APPEND)
	{
		if (i == 1)
			fprintf(stderr, "|");
		i = 1;
		fprintf(stderr, "O_APPEND");
	}
	if ((flags & O_NONBLOCK) == O_NONBLOCK)
	{
		if (i == 1)
			fprintf(stderr, "|");
		i = 1;
		fprintf(stderr, "O_NONBLOCK");
	}
	if ((flags & O_DSYNC) == O_DSYNC)
	{
		if (i == 1)
			fprintf(stderr, "|");
		i = 1;
		fprintf(stderr, "O_DSYNC");
	}
	if ((flags & O_ASYNC) == O_ASYNC)
	{
		if (i == 1)
			fprintf(stderr, "|");
		i = 1;
		fprintf(stderr, "O_ASYNC");
	}
	if ((flags & O_DIRECTORY) == O_DIRECTORY)
	{
		if (i == 1)
			fprintf(stderr, "|");
		i = 1;
		fprintf(stderr, "O_DIRECTORY");
	}
	if ((flags & O_NOFOLLOW) == O_NOFOLLOW)
	{
		if (i == 1)
			fprintf(stderr, "|");
		i = 1;
		fprintf(stderr, "O_NOFOLLOW");
	}
	if ((flags & O_CLOEXEC) == O_CLOEXEC)
	{
		if (i == 1)
			fprintf(stderr, "|");
		i = 1;
		fprintf(stderr, "O_CLOEXEC");
	}
	if ((flags & O_ASYNC) == O_ASYNC)
	{
		if (i == 1)
			fprintf(stderr, "|");
		i = 1;
		fprintf(stderr, "O_ASYNC");
	}
	if ((flags & O_SYNC) == O_SYNC)
	{
		if (i == 1)
			fprintf(stderr, "|");
		i = 1;
		fprintf(stderr, "O_SYNC");
	}
}
