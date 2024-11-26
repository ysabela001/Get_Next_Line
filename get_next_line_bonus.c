/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytavares <ytavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:06:17 by ytavares          #+#    #+#             */
/*   Updated: 2024/11/25 20:09:02 by ytavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_file_with_malloc(int fd, char *store_until_n)
{
	char	*buffer;
	char	*old_adress;
	int		store_read_bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(store_until_n, '\n'))
	{
		store_read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (store_read_bytes == -1)
			return (free(buffer), free(store_until_n), NULL);
		buffer[store_read_bytes] = '\0';
		old_adress = store_until_n;
		store_until_n = ft_strjoin(store_until_n, buffer);
		if (!store_until_n)
			return (free(buffer), free(old_adress), NULL);
		free (old_adress);
		if (store_read_bytes < BUFFER_SIZE)
			break ;
	}
	return (free(buffer), store_until_n);
}

void	extract_after_n(char *store_until_n, char **remainder_line)
{
	int	i;

	i = 0;
	while (store_until_n[i] != '\n' && store_until_n[i] != '\0')
		i++;
	if (store_until_n[i] == '\n')
	{
		free(*remainder_line);
		*remainder_line = ft_strdup(&store_until_n[i +1]);
		store_until_n[i + 1] = '\0';
	}
	else
	{
		free (remainder_line);
		*remainder_line = NULL;
	}
}

char	*get_next_line(int fd)
{
	char		*store_until_n;
	static char	*remainder_line[FD_SETSIZE];

	if (fd < 0 || fd >= FD_SETSIZE || BUFFER_SIZE <= 0)
		return (NULL);
	if (!remainder_line[fd])
		remainder_line[fd] = ft_strdup("");
	store_until_n = ft_strdup(remainder_line[fd]);
	if (!store_until_n)
		return (NULL);
	store_until_n = read_file_with_malloc(fd, store_until_n);
	if (!store_until_n || store_until_n[0] == '\0')
		return (free(store_until_n), free(remainder_line[fd]),
			remainder_line[fd] = NULL, NULL);
	if (ft_strchr(store_until_n, '\n'))
		extract_after_n(store_until_n, &remainder_line[fd]);
	return (store_until_n);
}
