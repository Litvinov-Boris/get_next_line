/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 20:40:56 by svivienn          #+#    #+#             */
/*   Updated: 2019/04/09 20:40:58 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	cntwords(char const *s, char c)
{
	size_t	i;
	int		in;

	i = 0;
	in = 0;
	while (*s != '\0')
	{
		if (in == 1 && *s == c)
			in = 0;
		if (in == 0 && *s != c)
		{
			in = 1;
			i++;
		}
		s++;
	}
	return (i);
}

static size_t	lenword(char const *s, char c)
{
	size_t i;

	i = 0;
	while (*s != c && *s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

static char		**clear(char **str, char **save)
{
	while (save >= str)
	{
		free(*save);
		save--;
	}
	free(str);
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	size_t	n;
	char	**save;

	if (s)
	{
		n = cntwords(s, c);
		if ((str = (char**)malloc(sizeof(*str) * (n + 1))) != NULL)
		{
			save = str;
			while (n--)
			{
				while (*s == c && *s != '\0')
					s++;
				if ((*save = ft_strsub(s, 0, lenword(s, c))) == NULL)
					return (clear(str, save));
				save++;
				s = s + lenword(s, c);
			}
			*save = NULL;
			return (str);
		}
	}
	return (NULL);
}
