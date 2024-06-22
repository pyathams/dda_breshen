/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 02:15:12 by pyathams          #+#    #+#             */
/*   Updated: 2024/05/17 16:27:00 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
size_t	ft_strlen1(const char *str);
char	*ft_strchr1(const char *s, int i);
char	*ft_strdup1(const char *s);
char	*ft_strjoin1(char const *s1, char const *s2);
char	*ft_substr1(const char *s, unsigned int start, size_t len);

#endif
