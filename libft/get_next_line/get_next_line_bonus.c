/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alex GEOFFROY <ageoffro@student.42lausa    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 10:40:59 by Alex GEOFFR       #+#    #+#             */
/*   Updated: 2026/02/11 09:18:14 by Alex GEOFFR      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	append_stat(char **stat, char *buf)
{
	char	*tmp;

	if (!stat)
		*stat = ft_strdup(" ");
	tmp = *stat;
	*stat = ft_strjoin(tmp, buf);
	free(tmp);
	if (!*stat)
		return (-1);
	return (0);
}

int	fill_stat(int fd, char **stat)
{
	char	*buf;
	ssize_t	bytes;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	bytes = 1;
	while (bytes > 0 && (!*stat || !ft_strrchr(*stat, '\n')))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
			return (free(buf), -1);
		if (bytes == 0)
			break ;
		buf[bytes] = '\0';
		if (append_stat(stat, buf) == -1)
			return (free(buf), -1);
	}
	free (buf);
	if (*stat && **stat == '\0')
	{
		free(*stat);
		*stat = NULL;
	}
	return (0);
}

static char	*extract_line(char **stat, t_data *data)
{
	if (!*stat)
		return (NULL);
	while ((*stat)[data->i] && (*stat)[data->i] != '\n')
		data->i++;
	if ((*stat)[data->i] == '\n')
	{
		data->line = ft_substr(*stat, 0, data->i + 1);
		if (!*stat)
			return (NULL);
		data->tmp = ft_strdup(*stat + data->i + 1);
		if (!*stat)
			return (NULL);
		free(*stat);
		if (data->tmp && data->tmp[0] == '\0')
		{
			free(data->tmp);
			data->tmp = NULL;
		}
		*stat = data->tmp;
		return (data->line);
	}
	data->line = ft_strdup(*stat);
	if (!*stat)
		return (NULL);
	return (free(*stat), *stat = NULL, data->line);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	lensrc;

	if (src == 0)
		return (0);
	lensrc = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (lensrc);
	while (i < size -1 && src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (lensrc);
}

char	*get_next_line(int fd)
{
	static char	*stat[1024];
	int			status;
	t_data		data;

	data.i = 0;
	data.line = NULL;
	data.tmp = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	status = fill_stat(fd, &stat[fd]);
	if (status == -1)
		return (free(stat[fd]), stat[fd] = NULL, NULL);
	return (extract_line(&stat[fd], &data));
}
