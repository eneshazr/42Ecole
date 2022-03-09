/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:20:03 by ehazir            #+#    #+#             */
/*   Updated: 2022/03/07 11:20:03 by ehazir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int		get_len(int nbr);
int		ekranayaz(char c);
int		stringyaz(char *str);
int		ptr_(unsigned long n);
int		ptryaz(unsigned long n);
int		basamakyay(unsigned int c);
int		unsigneditooo(unsigned int a);
int		ft_printf(const char *str, ...);
int		hex_system(unsigned int n, char c);
int		kontrol(va_list arg, const char c);

char	*ft_itoa(int n);
char	*ft_strdup(const char *str);

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif