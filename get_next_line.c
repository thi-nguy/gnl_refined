/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:35:37 by thi-nguy          #+#    #+#             */
/*   Updated: 2020/02/11 13:03:55 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

/*
get_line(str, line, i)
- We cut 'str' into 2 parts. One part from 0 to i we put in 'line'.
- The other part from i+1 to the end of 'str', we put in 'str' (or 'rest').
- Return (1) if there is no error. (-1) if error.
*/

int		get_line(char **str, char **line, int i)
{
	*line = ft_substr(*str, 0, i);
	if (*line == 0)
		return (-1);
	if (!(ft_strcpy(*str, *str + i + 1)))
		return (-1);
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
	static char		*rest = NULL;
	int				byte_read;
	int				i;

	/* TODO: Check error while reading file.
	- If there is no 'line'.
	- If we cannot read 0 byte into 'buff' ('read' returns value < 0).
	- If there is error, stop program, return -1.
	*/
	if (!line || read(fd, buff, 0) < 0) // Read 0 byte into buff.
		return (-1);

	/* TODO: If there is no ERROR, something in rest, we find '\n' in rest.
	We cut 'rest' by two parts by calling function get_line.Then END.
	- First part before '\n' we put into 'line'
	- Second part after '\n' we put back into 'rest'.
	*/
	if (rest && (((i = find_n(rest, '\n')) != -1)))
		return (get_line(&rest, line, i));

	/* TODO: Read BUFFER_SIZE bytes into buff. 
	2. End buff with '\0'
	3. Join buff into whatever is in rest at the moment to make a 'big rest'.(rest is the variable)
	4. If we find '\n' in 'big rest', we cut the 'big rest' by two parts by calling function get_line.Then END.
	- First part before '\n' we put into 'line'
	- Second part after '\n' we put back into 'rest'.
	5. If we don't fine '\n' in 'rest', we keep reading BUFFER_SIZE bytes into buff, until an error occurs (byte_read <0)
	*/
	while (((byte_read = read(fd, buff, BUFFER_SIZE)) > 0))
	{
		buff[byte_read] = '\0';
		rest = join_str(rest, buff);
		if (((i = find_n(rest, '\n')) != -1))
			return (get_line(&rest, line, i));
	}

	/* TODO: if there is something in 'rest'.
	- Copy what is in 'rest' to line.
	- Free 'rest'.
	- Return 'byte_read' and End program.
	*/
	if (rest)
	{
		*line = ft_strdup(rest);
		free(rest);
		rest = NULL;
		return (byte_read);
	}

	/* TODO:
	- Copy '\n' to line.
	- Return 'byte_read'.
	*/
	*line = ft_strdup("");
	return (byte_read);
}
