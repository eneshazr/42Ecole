/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <ehazir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:05:21 by ehazir            #+#    #+#             */
/*   Updated: 2022/10/24 14:32:32 by ehazir           ###   ########.TR       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				l_fork;
	int				r_fork;
	int				dead;
	int				eat_count;
	long long int	ph_eat_time;
	long long int	start_time;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				philo;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				ph_m_eat;
	int				one_died;
	int				all_eat;
	pthread_t		*threads;
	pthread_mutex_t	*forks;
	pthread_mutex_t	msg;
	pthread_mutex_t	death;
	t_philo			*philos;
}	t_data;

// --> CHECK <--
int				init_args_check(int ac, char **av);
int				ft_atoi(const char *str);
int				death_lock(t_philo *p);
int				ft_free(t_data *data);

// --> INIT <--
void			init_args(int ac, char **av, t_data *data);
int				forks(t_data *data);
int				philos(t_data *data);
void			eat_count(t_data *data, int i);

// --> THREADS <--
void			creat_threads(t_data *data);
long long int	get_time(void);
void			*worker(void *th);
void			one_philo(t_philo *pth);
void			go_sleep(int num);

// --> UTILS <--
void			philo_eat(t_philo *p);
void			philo_sleep(t_philo *p);
void			philo_think(t_philo *p);
int				death(t_data *data);
void			messages(int time, char *msg, t_philo *p);

#endif
