/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_mult.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 23:57:55 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/03/02 23:57:57 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*cast_tab(char **tab)
{
	char	*str;
	int		len;
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 0;
	len = 0;
	while (tab[i])
		len = len + ft_strlen(tab[i++]);
	str = (char*)malloc(sizeof(char) * (len + 2));
	i = 0;
	while (tab[y])
	{
		while (tab[y][x])
			str[i++] = tab[y][x++];
		x = 0;
		y++;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_strjoin_mult(int nb, ...)
{
	va_list ap;
	int		i;
	char	**tab;
	char	*str;

	va_start(ap, nb);
	tab = (char**)malloc(sizeof(char*) * (nb + 1));
	i = 0;
	while (i < nb)
	{
		tab[i] = ft_strdup(va_arg(ap, char*));
		i++;
	}
	tab[i] = NULL;
	va_end(ap);
	str = cast_tab(tab);
	ft_free_array(tab);
	return (str);
}
