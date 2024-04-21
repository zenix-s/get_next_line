/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:08:09 by serferna          #+#    #+#             */
/*   Updated: 2024/03/27 09:24:17 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	size_t	final_len;
	char	*substr;

	if (!str)
		return (NULL);
	if (start > ft_strlen(str))
		return (ft_strdup(""));
	final_len = ft_strlen(str + start);
	if (final_len < len)
		len = final_len;
	substr = (char *)ft_calloc(len + 1, sizeof(char));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, str + start, len + 1);
	return (substr);
}

char	*ft_strchr(const char *str, int chr)
{
	while (*str)
	{
		if (*str == (char)chr)
			return ((char *)str);
		str++;
	}
	if (*str == (char)chr)
		return ((char *)str);
	return (NULL);
}

/**
 * @name get_line_leave_rest
 * This function divides the text into two parts,
	the first part is the text until the first '\n' character
 * and the second part is the rest of the text.
 * @param text Is a pointer to the text that will be divided,
	it will be modified to contain the rest of the text.
 * @return The first part of the text until the first '\n' character.
 */
char	*get_line_leave_rest(char **text)
{
	int		i;
	int		len;
	char	*line;
	char	*rest;

	i = 0;
	if (!(*text)[i])
		return (NULL);
	len = ft_strlen(*text);
	while ((*text)[i] != '\n' && (*text)[i] != '\0')
		i++;
	line = ft_substr(*text, 0, i + 1);
	rest = ft_substr(*text, i + 1, len - i);
	if (!line || !rest)
	{
		free(*text);
		return (NULL);
	}
	free(*text);
	*text = rest;
	return (line);
}

char	*read_file(int fd, char *text)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*tmp;
	int		bytes_read;

	bytes_read = 1;
	while (!ft_strchr(text, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if ((bytes_read == 0 && !ft_strlen(text)) || bytes_read < 0)
		{
			free(text);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		tmp = text;
		text = ft_strjoin(text, buffer);
		free(tmp);
	}
	return (text);
}

char	*get_next_line(int fd)
{
	static char	*text[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!text[fd])
		text[fd] = ft_strdup("");
	text[fd] = read_file(fd, text[fd]);
	if (!text[fd])
		return (NULL);
	if (!ft_strchr(text[fd], '\n'))
	{
		line = ft_strdup(text[fd]);
		free(text[fd]);
		text[fd] = NULL;
		return (line);
	}
	else
	{
		line = get_line_leave_rest(&text[fd]);
		return (line);
	}
}
