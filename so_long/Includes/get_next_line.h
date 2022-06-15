/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:13:26 by ehazir            #+#    #+#             */
/*   Updated: 2022/06/15 12:14:33 by ehazir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*get_line(char *src, int fd);
char	*ft_read_line(char *src);
char	*ft_save(char *src);
char	*ft_strjoin1(char *s1, char *s2);
size_t	ft_strlen1(char *src);
char	*ft_strchr1(char *src, int c);

#endif
