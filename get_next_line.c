/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytavares <ytavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:08:32 by ytavares          #+#    #+#             */
/*   Updated: 2024/11/14 16:14:24 by ytavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h";

char	*validation(int fd, int (BUFFER_SIZE), char *store_data)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!store_data)
	{
		store_data = (char *)malloc(1 * sizeof(char));
		if (!store_data)
			return (NULL);
	store_data[0] = '\0';
	}
	return (store_data);
}

char	*get_next_line(int fd)
{
	char	buffer_read;
	ssize_t	bytes_read;

	buffer_read = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer_read)
		return (NULL);
	while 
}



