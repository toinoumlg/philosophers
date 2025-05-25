/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:39:04 by amalangu          #+#    #+#             */
/*   Updated: 2025/05/25 19:32:42 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_mutex(pthread_mutex_t *forks, int nbr_of_philo)
{
	int	i;

	i = 0;
	while (i < nbr_of_philo)
		pthread_mutex_init(&forks[i++], NULL);
}

void	set_philos_mutex(t_philo *philos, pthread_mutex_t *forks, int size,
		pthread_mutex_t *write)
{
	int	i;

	i = -1;
	while (++i < size - 1)
	{
		philos[i].id = i + 1;
		philos[i].fork_l = &forks[i];
		philos[i].fork_r = &forks[i + 1];
		philos[i].write = write;
	}
	philos[i].id = i + 1;
	philos[i].write = write;
	philos[i].fork_l = &forks[i];
	philos[i].fork_r = &forks[0];
}

void	set_philos_data(t_philo *philos, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_of_philo)
	{
		philos[i].dead_flag = &data->dead_flag;
		philos[i].meal_flag = &data->meal_flag;
		philos[i].tt_eat = data->tt_eat;
		philos[i++].tt_sleep = data->tt_sleep;
	}
}
size_t	get_time_since_start(size_t start)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (((tv.tv_sec * 1000) + (tv.tv_usec / 1000)) - start);
}
void	parse_arguments(int argc, char **argv, t_data *data)
{
	if (argc < 5 || argc > 7)
		exit(1);
	data->nbr_of_philo = atoi(argv[1]);
	data->dead_flag = 0;
	data->meal_flag = 0;
	data->tt_die = atoi(argv[2]);
	data->tt_eat = atoi(argv[3]);
	data->tt_sleep = atoi(argv[4]);
	data->meals_goal = atoi(argv[5]);
	data->philos = malloc(sizeof(t_philo) * data->nbr_of_philo);
	memset(data->philos, 0, sizeof(t_philo) * data->nbr_of_philo);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nbr_of_philo);
	memset(data->forks, 0, sizeof(pthread_mutex_t) * data->nbr_of_philo);
	data->write = malloc(sizeof(pthread_mutex_t));
	memset(data->write, 0, sizeof(pthread_mutex_t));
	init_mutex(data->forks, data->nbr_of_philo);
	pthread_mutex_init(data->write, NULL);
	set_philos_mutex(data->philos, data->forks, data->nbr_of_philo,
		data->write);
	set_philos_data(data->philos, data);
	return ;
}

void	print_fork_lock(t_philo *philo)
{
	if (*philo->dead_flag)
		return ;
	pthread_mutex_lock(philo->write);
	printf("%ld %d has taken a fork\n", get_time_since_start(philo->start),
		philo->id);
	pthread_mutex_unlock(philo->write);
}

void	pick_up_fork(pthread_mutex_t *fork, t_philo *philo)
{
	pthread_mutex_lock(fork);
	print_fork_lock(philo);
}

void	print_eat_lock(t_philo *philo)
{
	if (*philo->dead_flag)
		return ;
	pthread_mutex_lock(philo->write);
	printf("%ld %d is eating\n", get_time_since_start(philo->start), philo->id);
	pthread_mutex_unlock(philo->write);
}

void	pick_up_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pick_up_fork(philo->fork_l, philo);
		pick_up_fork(philo->fork_r, philo);
	}
	else
	{
		pick_up_fork(philo->fork_r, philo);
		pick_up_fork(philo->fork_l, philo);
	}
	if (*philo->dead_flag)
		return ;
	print_eat_lock(philo);
}

void	unlock_forks(pthread_mutex_t *fork1, pthread_mutex_t *fork2)
{
	pthread_mutex_unlock(fork1);
	pthread_mutex_unlock(fork2);
}
void	try_eat(t_philo *philo)
{
	pick_up_forks(philo);
	philo->last_meal = get_time_since_start(philo->start);
	usleep(philo->tt_eat * 1000);
	unlock_forks(philo->fork_l, philo->fork_r);
	philo->meals_eaten++;
}

void	print_sleep_lock(t_philo *philo)
{
	if (*philo->dead_flag)
		return ;
	pthread_mutex_lock(philo->write);
	printf("%ld %d is sleeping\n", get_time_since_start(philo->start),
		philo->id);
	pthread_mutex_unlock(philo->write);
}

void	go_sleep(t_philo *philo)
{
	print_sleep_lock(philo);
	usleep(philo->tt_sleep * 1000);
}

void	print_think_lock(t_philo *philo)
{
	if (*philo->dead_flag)
		return ;
	pthread_mutex_lock(philo->write);
	printf("%ld %d is thinking\n", get_time_since_start(philo->start),
		philo->id);
	pthread_mutex_unlock(philo->write);
}

void	go_think(t_philo *philo)
{
	print_think_lock(philo);
}

void	*start_philo_routine(void *philo_add)
{
	t_philo	*philo;

	philo = (t_philo *)philo_add;
	philo->last_meal = get_time_since_start(philo->start);
	while (*philo->dead_flag == 0 && *philo->meal_flag == 0)
	{
		if (*philo->dead_flag)
			break ;
		try_eat(philo);
		if (*philo->dead_flag)
			break ;
		go_sleep(philo);
		if (*philo->dead_flag)
			break ;
		go_think(philo);
	}
	return (NULL);
}

void	destroy_mutex(pthread_mutex_t *forks, int size)
{
	int	i;

	i = 0;
	while (i < size)
		pthread_mutex_destroy(&forks[i++]);
}

void	init_philos_threads(t_data *data)
{
	int				i;
	struct timeval	tv;
	size_t			start;

	i = 0;
	gettimeofday(&tv, NULL);
	start = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	while (i < data->nbr_of_philo)
	{
		data->philos[i].start = start;
		pthread_create(&data->philos[i].thread, NULL, start_philo_routine,
			(void *)&data->philos[i]);
		i++;
	}
}

void	join_philos_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_of_philo)
		pthread_join(data->philos[i++].thread, NULL);
}

void	print_dead_lock(t_philo *philo)
{
	pthread_mutex_lock(philo->write);
	printf("%ld %d died\n", get_time_since_start(philo->start), philo->id);
	pthread_mutex_unlock(philo->write);
}

void	*start_death_watcher_routine(void *data_add)
{
	t_data	*data;
	int		i;

	data = (t_data *)data_add;
	usleep(1000);
	while (!data->meal_flag)
	{
		i = 0;
		while (i < data->nbr_of_philo && !data->meal_flag)
		{
			if ((get_time_since_start(data->philos[i].start)
					- data->philos[i].last_meal > data->tt_die))
			{
				data->dead_flag = 1;
				print_dead_lock(&data->philos[i]);
				return (NULL);
			}
		}
	}
	return (NULL);
}

void	*start_meals_watcher_routine(void *data_add)
{
	t_data	*data;
	int		i;

	data = (t_data *)data_add;
	i = 0;
	while (i < data->nbr_of_philo)
	{
		if (data->philos[i].meals_eaten < data->meals_goal)
			i = 0;
		else
			i++;
	}
	data->meal_flag = 1;
	return (NULL);
}

void	init_watcher_thread(t_data *data)
{
	pthread_t	watcher1;
	pthread_t	watcher2;

	pthread_create(&watcher1, NULL, start_death_watcher_routine, (void *)data);
	pthread_create(&watcher2, NULL, start_meals_watcher_routine, (void *)data);
	pthread_join(watcher1, NULL);
	pthread_join(watcher2, NULL);
}

int	main(int argc, char **argv)
{
	t_data	data;

	parse_arguments(argc, argv, &data);
	init_philos_threads(&data);
	init_watcher_thread(&data);
	join_philos_threads(&data);
	destroy_mutex(data.forks, data.nbr_of_philo);
	free(data.forks);
	free(data.philos);
	// init_philos();
}
