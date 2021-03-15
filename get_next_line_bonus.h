/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 17:32:14 by thi-nguy          #+#    #+#             */
/*   Updated: 2020/02/11 13:10:38 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>

char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, int start, int len);
char	*ft_strcpy(char *dst, const char *src);
char	*join_str(char *s1, char *s2);
int		find_n(const char *str, int c);
int		get_line(char **str, char **line, int i);
int		get_next_line(int fd, char **line);

#endif
