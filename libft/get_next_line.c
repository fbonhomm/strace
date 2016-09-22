/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 15:35:42 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/09/29 17:09:25 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_read_line(char **line, t_env *env, int fd, char *buff)
{
	int p;

	ft_bzero(buff, SIZE + 1);
	if ((env->rd = read(fd, buff, SIZE)) < 0)
		return (1);
	if (!buff[0])
	{
		(*line)[0] = buff[0];
		(*line)[1] = '\0';
		return (1);
	}
	if (buff[0] == '\n')
	{
		(*line)[0] = buff[0];
		(*line)[1] = '\0';
		return (3);
	}
	if (env->rd == 0)
		return (0);
	while ((buff[env->i] && buff[env->i] != '\n'))
	{
		if ((p = ft_in_read_line(line, env, fd, buff)) != 2)
			return (p);
	}
	return (2);
}

static char			*ft_curse(t_env *env, char *cursor, char *buff)
{
	env->i++;
	if (cursor && cursor[0])
		cursor = ft_free(cursor);
	cursor = ft_strnew(ft_strlen(buff));
	while (buff[env->i] != '\0')
	{
		cursor[env->j] = buff[env->i];
		env->i++;
		env->j++;
	}
	cursor[env->j] = '\0';
	return (cursor);
}

void				ft_cursor(char *cursor, char **line, t_env *env)
{
	while ((cursor) && (*cursor != '\n') && (*cursor != '\0'))
	{
		(*line)[env->j] = *cursor;
		env->j++;
		cursor++;
	}
}

void				ft_insertion(char **line, int fd, t_env *env, char *cursor)
{
	char			buff[SIZE + 1];
	char			*tmp;

	env->j = 0;
	if (cursor)
		ft_cursor(cursor, line, env);
	if (((!cursor) || (*cursor != '\n')))
	{
		if ((env->ret = ft_read_line(line, env, fd, buff)) == 1)
			return ;
		if (env->ret == 3)
			return ;
		(*line)[env->j] = '\0';
		if (env->ret == 0)
			return ;
		env->j = 0;
		if (buff[env->i] == '\n' && buff[env->i + 1] != '\0')
			cursor = ft_curse(env, cursor, buff);
	}
	tmp = cursor;
	(*line)[env->j] = '\0';
	cursor++;
	tmp = ft_free(tmp);
}

int					get_next_line(int const fd, char **line)
{
	t_env			env;
	static char		*cursor;

	if (line == NULL || fd < 0 || SIZE <= 0)
		return (-1);
	if (!(*line = (char*)ft_strnew(sizeof(char) * (SIZE + 1))))
		return (-1);
	env.i = 0;
	env.ind = 0;
	env.rd = 1;
	env.ret = 2;
	ft_insertion(line, fd, &env, cursor);
	if (env.ret == 0)
		return (0);
	if (env.ret == 3)
	{
		cursor = NULL;
		return (0);
	}
	if (env.ret == 1)
		return (-1);
	return (1);
}
