/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumallet <gumallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:47:52 by gumallet          #+#    #+#             */
/*   Updated: 2024/12/13 14:38:39 by gumallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>

static int	ft_check_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*ft_clean_line(char *line)
{
	int	newline_pos;

	newline_pos = ft_check_nl(line);
	if (newline_pos != -1)
	{
		line[newline_pos + 1] = '\0';
	}
	return (line);
}

static char	*ft_use_rest(char **rest, char *line)
{
	char	*temp;

	temp = ft_substr(*rest, (ft_check_nl(*rest) + 1), -1);
	safe_free(rest);
	*rest = temp;
	line = ft_clean_line(line);
	return (line);
}

static char	*ft_fill_line(int fd, char **rest, char *buffer)
{
	char	*line;
	int		chars_read;

	line = ft_strdup("");
	if (*rest)
	{
		line = ft_strjoin(line, *rest);
		if (ft_check_nl(*rest) != -1)
			return (ft_use_rest(rest, line));
		safe_free(rest);
	}
	chars_read = read(fd, buffer, BUFFER_SIZE);
	buffer[chars_read] = '\0';
	if (chars_read == -1 || (chars_read == 0 && !ft_strlen(line)))
		return (free(line), NULL);
	while (ft_check_nl(buffer) == -1 && chars_read == BUFFER_SIZE)
	{
		line = ft_strjoin(line, buffer);
		chars_read = read(fd, buffer, BUFFER_SIZE);
		if (chars_read != BUFFER_SIZE)
			buffer[chars_read] = '\0';
	}
	if (ft_check_nl(buffer) != -1)
		*rest = ft_substr(buffer, (ft_check_nl(buffer) + 1), -1);
	return (line = ft_strjoin(line, buffer), line = ft_clean_line(line), line);
}

char	*get_next_line(int fd)
{
	static char	*rest = NULL;
	char		buffer[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 8000000)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	line = ft_fill_line(fd, &rest, buffer);
	return (line);
}
