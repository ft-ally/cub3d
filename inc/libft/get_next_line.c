/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:47:55 by tcakir-y          #+#    #+#             */
/*   Updated: 2025/03/04 21:28:40 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*malloc_free(char	**s, char **buf)
{
	if (s && *s)
	{
		free(*s);
		*s = NULL;
	}
	if (buf && *buf)
	{
		free(*buf);
		*buf = NULL;
	}
	return (NULL);
}

static char	*after_nl(char *whole_file)
{
	int		i;
	int		j;
	char	*after_nl;

	i = 0;
	j = 0;
	if (whole_file == NULL)
		return (malloc_free(&whole_file, NULL));
	while (whole_file[i] != '\n' && whole_file[i] != '\0')
		i++;
	if (whole_file[i] == '\0')
		return (malloc_free(&whole_file, NULL));
	after_nl = ft_calloc(ft_strlen(whole_file) - i + 1, sizeof(char));
	if (after_nl == NULL)
		return (malloc_free(&after_nl, &whole_file));
	i++;
	while (whole_file[i] != '\0')
		after_nl[j++] = whole_file[i++];
	free(whole_file);
	return (after_nl);
}

static char	*until_nl(char *whole_file)
{
	int		i;
	char	*line_until_nl;

	i = 0;
	if (whole_file == NULL || whole_file[i] == '\0')
		return (NULL);
	while (whole_file[i] != '\0' && whole_file[i] != '\n')
		i++;
	if (whole_file[i] == '\n')
		i++;
	line_until_nl = ft_calloc((i + 1), sizeof(char));
	if (line_until_nl == NULL)
		return (malloc_free(&line_until_nl, NULL));
	i = 0;
	while (whole_file[i] != '\0' && whole_file[i] != '\n')
	{
		line_until_nl[i] = whole_file[i];
		i++;
	}
	if (whole_file[i] == '\n')
		line_until_nl[i++] = '\n';
	line_until_nl[i] = '\0';
	return (line_until_nl);
}

static char	*read_from_file(int fd, char *whole_file, int *bytes_read)
{
	char	*buffer;
	char	*temp;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (whole_file == NULL)
		whole_file = ft_calloc(1, sizeof(char));
	if (!buffer || !whole_file)
		return (malloc_free(&whole_file, &buffer));
	while (*bytes_read != 0 && !ft_strchr(whole_file, '\n'))
	{
		*bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (*bytes_read == -1)
			return (malloc_free(&buffer, &whole_file));
		buffer[*bytes_read] = '\0';
		temp = whole_file;
		if (buffer == NULL || temp == NULL)
			return (malloc_free(&buffer, &whole_file));
		whole_file = ft_strjoin(temp, buffer);
		if (whole_file == NULL)
			return (malloc_free(&temp, &buffer));
		free(temp);
	}
	free(buffer);
	return (whole_file);
}

/// @brief 
/// @param fd 
/// @return line until newline or NULL
char	*get_next_line(int fd)
{
	static char	*whole_file;
	int			bytes_read;
	char		*line_until_nl;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = 1;
	whole_file = read_from_file(fd, whole_file, &bytes_read);
	if (whole_file == NULL)
		return (malloc_free(&whole_file, NULL));
	line_until_nl = until_nl(whole_file);
	if (line_until_nl == NULL)
		return (malloc_free(&whole_file, NULL));
	whole_file = after_nl(whole_file);
	if (line_until_nl == NULL && bytes_read == 0)
		return (malloc_free(&whole_file, NULL));
	return (line_until_nl);
}

//fd == 0 > stdin
//fd == 1 > stdout
//fd == 2 > stderror
//fd == 3 > reading from a file
//read returns ->  
//  0 on reaching the end of file
// -1 on error or signal interrupt
