/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:29:25 by ehazir            #+#    #+#             */
/*   Updated: 2022/04/28 12:29:29 by ehazir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	binarytodecimal(char *bits)
{
	int				base;
	unsigned char	num;
	int				i;

	num = 0;
	i = 0;
	base = 128;
	while (bits[i])
	{
		num += base * (bits[i] - '0');
		base /= 2;
		i++;
	}
	write(1, &num, 1);
}

void	ft_signal(int signal)
{
	static int	counter;
	static char	*bits;

	if (bits == NULL)
	{
		bits = ft_strdup("");
		counter = 1;
	}
	if (signal == SIGUSR1)
		bits = ft_strjoin(bits, '0');
	else
		bits = ft_strjoin(bits, '1');
	if (counter == 8)
	{
		binarytodecimal(bits);
		free(bits);
		bits = NULL;
	}
	counter++;
}

int	main(void)
{
	int		pid;
	char	*pidstr;

	pid = getpid();
	ft_putstr("PID: ");
	pidstr = ft_itoa(pid);
	ft_putstr(pidstr);
	write(1, "\n", 1);
	while (1)
	{
		signal(SIGUSR1, ft_signal);
		signal(SIGUSR2, ft_signal);
		pause();
	}
	return (0);
}
