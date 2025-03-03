/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalizon <ggalizon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:03:44 by ggalizon          #+#    #+#             */
/*   Updated: 2024/12/20 15:20:41 by ggalizon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*merge_str(const char *s1, const char *s2)
{
	char	*merged;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	merged = malloc((len1 + len2 + 1) * sizeof(char));
	if (!merged)
		return (NULL);
	if (s1)
		ft_memcpy(merged, s1, len1);
	if (s2)
		ft_memcpy(merged + len1, s2, len2);
	merged[len1 + len2] = '\0';
	return (merged);
}

static int	handle_merge(char **leftovers, char **buff)
{
	char	*temp;

	temp = *leftovers;
	*leftovers = merge_str(*leftovers, *buff);
	free(temp);
	if (!*leftovers)
	{
		free(*buff);
		return (-1);
	}
	return (1);
}

static int	read_and_keep(int fd, char **leftovers)
{
	char	*buff;
	ssize_t	bytes_read;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (-1);
	bytes_read = read(fd, buff, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buff[bytes_read] = '\0';
		if (*leftovers)
			handle_merge(leftovers, &buff);
		else
			*leftovers = ft_strdup(buff);
		if (ft_strchr(*leftovers, '\n'))
			break ;
		bytes_read = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	if (bytes_read < 0 && *leftovers)
	{
		free(*leftovers);
		*leftovers = NULL;
	}
	return (bytes_read);
}

static char	*set_line(char **leftovers)
{
	int		i;
	char	*temp;
	char	*line;

	i = 0;
	while ((*leftovers)[i] != '\n' && (*leftovers)[i] != '\0')
		i++;
	if ((*leftovers)[i] == '\n')
	{
		line = ft_substr(*leftovers, 0, i + 1);
		temp = *leftovers;
		*leftovers = ft_strdup(temp + i + 1);
		free(temp);
		if (!*leftovers || !line)
			return (NULL);
	}
	else
	{
		line = ft_strdup(*leftovers);
		if (!line)
			return (NULL);
		free(*leftovers);
		*leftovers = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*leftovers;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = read_and_keep(fd, &leftovers);
	if (bytes_read < 0 || (!leftovers && bytes_read == 0))
	{
		free(leftovers);
		return (NULL);
	}
	if (leftovers && *leftovers != '\0')
	{
		line = set_line(&leftovers);
		return (line);
	}
	if (leftovers)
	{
		free(leftovers);
		leftovers = NULL;
	}
	return (NULL);
}
