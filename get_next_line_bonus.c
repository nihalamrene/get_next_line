/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namrene <namrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:09:24 by namrene           #+#    #+#             */
/*   Updated: 2023/11/24 21:31:30 by namrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*add_reserve(int fd, char *reserve)
{
	char	*buf;
	int		nbrd;

	nbrd = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!ft_strchr(reserve, '\n') && nbrd != 0)
	{
		nbrd = read(fd, buf, BUFFER_SIZE);
		if (nbrd == (-1))
		{
			free(reserve);
			free(buf);
			return (NULL);
		}
		buf[nbrd] = '\0';
		reserve = ft_strjoin(reserve, buf);
	}
	free(buf);
	return (reserve);
}

char	*new_reserve(char *reserve)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (reserve[i] && reserve[i] != '\n')
		i++;
	if (!reserve[i])
	{
		free(reserve);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(reserve) - i + 1));
	if (!str)
		return (NULL);
	i++;
	while (reserve[i])
		str[j++] = reserve[i++];
	str[j] = '\0';
	free(reserve);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*reserve[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (fd >= 0)
			free(reserve[fd]);
		return (0);
	}
	reserve[fd] = add_reserve(fd, reserve[fd]);
	if (!reserve[fd])
	{
		free(reserve[fd]);
		return (NULL);
	}
	line = turn_line(reserve[fd]);
	reserve[fd] = new_reserve(reserve[fd]);
	return (line);
}
