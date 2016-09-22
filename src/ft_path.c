/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 18:02:19 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/10/30 18:02:21 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strace.h"

char		*pathfinding(t_strc *strc)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strdup(strc->tab[0]);
	while ((strc->path && strc->path[i]))
	{
		if ((access(tmp, F_OK)) == 0)
			return (tmp);
        tmp = ft_free(tmp);
		tmp = ft_strjoin_mult(3, strc->path[i], "/", strc->tab[0]);
		i++;
	}
	tmp = ft_free(tmp);
	ft_print_str_endl(3, "ft_strace: Can't stat '", strc->tab[0],
                        "': No such file or directory\n");
	exit(-1);
	return (0);
}

char        *ft_path(t_strc *strc, char **env)
{
	int     i;

	i = 0;
	while (env && env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
            strc->path = ft_split(env[i], ':', '=');
			break ;
		}
		i++;
	}
	return (pathfinding(strc));
}
