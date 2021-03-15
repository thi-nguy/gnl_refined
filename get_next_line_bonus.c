/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 17:34:11 by thi-nguy          #+#    #+#             */
/*   Updated: 2020/02/11 13:07:07 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*join_str(char *s1, char *s2)
{
	int		len1;
	int		len2;
	int		i;
	char	*dst;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(dst = (char*)malloc((len1 + len2 + 1) * sizeof(char))))
		return (NULL);
	i = -1;
	while (s1[++i])
		dst[i] = s1[i];
	free(s1);
	s1 = NULL;
	i = -1;
	while (s2[++i])
		dst[len1 + i] = s2[i];
	dst[len1 + i] = '\0';
	return (dst);
}

int		find_n(const char *str, int c)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		get_line(char **str, char **line, int i)
{
	*line = ft_substr(*str, 0, i);
	ft_strcpy(*str, *str + i + 1);
	if (**str == '\0')
	{
		free(*str);
		*str = NULL;
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	char			buff[BUFFER_SIZE + 1];
	static char		*rest[100000];
	int				byte_read;
	int				i;

	if (!line || fd < 0 || BUFFER_SIZE < 1 || read(fd, buff, 0) < 0)
		return (-1);
	if (rest[fd] && (((i = find_n(rest[fd], '\n')) != -1)))
		return (get_line(&rest[fd], line, i));
	while (((byte_read = read(fd, buff, BUFFER_SIZE)) > 0))
	{
		buff[byte_read] = '\0';
		rest[fd] = join_str(rest[fd], buff);
		if (((i = find_n(rest[fd], '\n')) != -1))
			return (get_line(&rest[fd], line, i));
	}
	if (rest[fd])
	{
		*line = ft_strdup(rest[fd]);
		free(rest[fd]);
		rest[fd] = NULL;
		return (byte_read);
	}
	*line = ft_strdup("");
	return (byte_read);
}
