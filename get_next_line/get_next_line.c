/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:25:24 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/02/13 15:10:18 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*extract_line(char **buffer)
{
	char	*newline;
	char	*line;
	char	*leftover;

	if (!*buffer)
		return (NULL);
	newline = ft_strchr(*buffer, '\n');
	if (!newline)
		return (NULL);
	line = ft_substr(*buffer, 0, newline - *buffer + 1);
	leftover = ft_strdup(newline + 1);
	free(*buffer);
	*buffer = leftover;
	return (line);
}

int	read_and_append(int fd, char **buffer)
{
	char	*temp;
	int		bytes_read;
	char	*new_buffer;

	temp = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp)
		return (-1);
	bytes_read = read(fd, temp, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(temp);
		return (bytes_read);
	}
	temp[bytes_read] = '\0';
	new_buffer = ft_strjoin(*buffer, temp);
	free(*buffer);
	if (!new_buffer)
	{
		free(temp);
		return (-1);
	}
	free(temp);
	*buffer = new_buffer;
	return (bytes_read);
}

char	*handle_eof(char **buffer)
{
	char	*line;

	line = NULL;
	if (*buffer && **buffer)
		line = ft_strdup(*buffer);
	free(*buffer);
	*buffer = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	int			byte_read;
	static int	eof_flag = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (eof_flag)
		return (NULL);
	if (!buffer)
		buffer = ft_strdup("");
	while (1)
	{
		if (ft_strchr(buffer, '\n'))
			return (extract_line(&buffer));
		byte_read = read_and_append(fd, &buffer);
		if (byte_read < 0)
			return (NULL);
		if (byte_read == 0)
		{
			eof_flag = 1;
			return (handle_eof(&buffer));
		}
	}
	return (NULL);
}
