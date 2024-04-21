/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:18:40 by serferna          #+#    #+#             */
/*   Updated: 2024/03/26 11:36:37 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

void	*ft_calloc(size_t count, size_t len);

size_t	ft_strlen(const char *str);

char	*ft_strdup(const char *str);

char	*ft_strjoin(const char *s1, const char *s2);

char	*ft_strchr(const char *str, int chr);

size_t	ft_strlcpy(char *dst, const char *src, size_t len);

char	*ft_substr(const char *str, unsigned int start, size_t len);

char	*get_next_line(int fd);

#endif
