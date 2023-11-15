/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briveiro <briveiro@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:40:52 by briveiro          #+#    #+#             */
/*   Updated: 2023/11/08 19:02:40 by briveiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_get_rest(char *buffer)
{
	size_t	len;
	size_t	count;
	char	*changer;

	len = 0;
	while (buffer[len] != '\0' && buffer[len] != '\n')
		len++;
	if (buffer[len] == '\n' && buffer[len + 1] != '\0')
	{
		changer = ft_calloc(ft_strlen(buffer) - len + 1, sizeof(char));
		if (!changer)
			return (free(changer), NULL);
		len++;
		count = 0;
		while (buffer[len] != '\0')
			changer[count++] = buffer[len++];
		free(buffer);
		buffer = NULL;
		return (changer);
	}
	return (free(buffer), NULL);
}

static char	*ft_get_line(char *buf)
{
	size_t	len;
	size_t	count;
	char	*changer;

	len = 0;
	if (!buf)
		return (NULL);
	while (buf[len] && buf[len] != '\n')
		len++;
	changer = (char *)ft_calloc(len + 2, sizeof(char));
	if (!changer)
		return (free(changer), NULL);
	count = 0;
	while (buf[count] && buf[count] != '\n')
	{
		changer[count] = buf[count];
		count++;
	}
	if (buf[count] == '\n')
		changer[count++] = '\n';
	return (changer);
}

static char	*ft_main_read(int fd, char *buffer)
{
	char	*changer;
	int		reader;

	reader = 42;
	changer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!changer)
		return (free(changer), NULL);
	while (!(ft_strchr(buffer, '\n')) && reader != 0)
	{
		reader = read(fd, changer, BUFFER_SIZE);
		if (reader < 0)
		{
			free(buffer);
			free(changer);
			return (NULL);
		}
		else if (reader == 0)
			return (free(changer), buffer);
		buffer = ft_insert(buffer, changer);
		changer = cleaner(changer);
	}
	free(changer);
	changer = NULL;
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[4096];
	char		*get;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer[fd] = ft_main_read(fd, buffer[fd]);
	if (!buffer[fd])
		return (free(buffer[fd]), NULL);
	get = ft_get_line(buffer[fd]);
	buffer[fd] = ft_get_rest(buffer[fd]);
	return (get);
}

char	*cleaner(char *clean)
{
	int	count;

	count = -1;
	while (clean[++count])
	{
		clean[count] = '\0';
	}
	return (clean);
}
