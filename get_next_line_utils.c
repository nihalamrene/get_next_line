/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namrene <namrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:12:50 by namrene           #+#    #+#             */
/*   Updated: 2023/11/24 20:52:46 by namrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	res = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	if (s1 != NULL)
	{
		while (s1[i] != '\0')
			res[j++] = s1[i++];
		free(s1);
	}
	i = 0;
	while (s2 != NULL && s2[i] != '\0')
		res[j++] = s2[i++];
	res[j] = '\0';
	return (res);
}

char	*copy_line(char *reserve, int *line_length)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (reserve[i] && reserve[i] != '\n')
		i++;
	*line_length = i;
	if (reserve[i] == '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (reserve[j] && reserve[j] != '\n')
	{
		line[j] = reserve[j];
		j++;
	}
	if (reserve[j] == '\n')
	{
		line[j] = reserve[j];
		j++;
	}
	return (line[j] = '\0', line);
}

char	*turn_line(char *reserve)
{
	int		line_length;
	char	*line;

	if (!reserve || !reserve[0])
		return (NULL);
	line = copy_line(reserve, &line_length);
	reserve += line_length;
	return (line);
}
