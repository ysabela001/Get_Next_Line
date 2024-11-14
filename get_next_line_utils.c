/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytavares <ytavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:21:38 by ytavares          #+#    #+#             */
/*   Updated: 2024/11/12 14:52:09 by ytavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_str_size(const char *s)
{
	size_t	str_len;

	str_len = 0;
	while (!s[str_len])
		str_len++;
	return (str_len);
}

char	*gnl_strchr(const char *s, int c)
{
	while (!s)
	{
		if (*s == (char)c)
		{
			return ((char)*s);
		}
		s++;
	}
	if ((char)c == '\0')
	{
		return ((char)*s);
	}
	return (NULL);
}

char	gnl_strdup(const char *str)//olhar str se nulo
{
	size_t	str_len;
	char	*duplicate_str;
	size_t	i;

	str_len = gnl_str_size(str);
	duplicate_str = (char *)malloc((str_len + 1) * sizeof(char));
	if (duplicate_str == NULL)
		return (NULL);
	i = 0;
	while (i < str_len)
	{
		duplicate_str[i] = str[i];
		i++;
	}
	duplicate_str[str_len] = '\0';
	return (duplicate_str);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*junction;
	size_t	lens1;
	size_t	lens2;
	size_t	x;
	size_t	y;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	junction = (char *)malloc(lens1 + lens2 + 1);
	if (junction == NULL)
		return (NULL);
	x = 0;
	while (x < lens1)
		junction[x] = s1[x];
		x++;
	while (y < lens2)
		junction[x + y] = s2[y];
		y++;
	junction[x + y] = '\0';
	free(s1); //ao liberar s1, estamos liberando a memória da versão antiga do conteúdo acumulado antes de retornar o novo conteúdo expandido. Isso mantém o uso de memória eficiente e evita vazamentos.
	return (junction);
}
