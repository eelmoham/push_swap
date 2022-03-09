/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:42:24 by eelmoham          #+#    #+#             */
/*   Updated: 2021/12/02 09:44:57 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*text[MAX_FD];
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
	if (!text[fd])
		text[fd] = ft_strdup("");
	bytes = read_file(&text[fd], fd, &buffer);
	line = ft_line(&line, &text[fd]);
	if (!bytes && *line == '\0')
	{
		free(line);
		return (0);
	}
	return (line);
}
