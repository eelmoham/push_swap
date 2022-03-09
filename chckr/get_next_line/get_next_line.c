/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:39:09 by eelmoham          #+#    #+#             */
/*   Updated: 2021/11/30 17:39:13 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line(char **line, char **text);

int	read_file(char **text, int fd, char **buffer)
{
	char	*forfree;
	int		bytes;

	bytes = 1;
	while (bytes && !ft_strchr(*text, '\n'))
	{
		bytes = read(fd, *buffer, BUFFER_SIZE);
		(*buffer)[bytes] = '\0';
		forfree = *text;
		*text = ft_strjoin(*text, *buffer);
		free(forfree);
	}
	free(*buffer);
	return (bytes);
}

char	*ft_line(char **line, char **text)
{
	int		i;
	char	*forfree;

	i = 0;
	forfree = *text;
	while ((*text)[i] != '\n' && (*text)[i] != '\0')
		i++;
	if (ft_strchr(*text, '\n'))
	{
		*line = ft_substr(*text, 0, i + 1);
		*text = ft_strdup(*text + i + 1);
	}
	else
	{
		*line = ft_strdup(forfree);
		*text = NULL;
	}
	free(forfree);
	return (*line);
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		*buffer;
	char		*line;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	if (read(fd, buffer, 0) < 0)
	{
		free(buffer);
		return (0);
	}
	if (!text)
		text = ft_strdup("");
	bytes = read_file(&text, fd, &buffer);
	line = ft_line(&line, &text);
	if (!bytes && *line == '\0')
	{
		free(line);
		return (0);
	}
	return (line);
}
