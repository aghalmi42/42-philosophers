/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 21:41:11 by aghalmi           #+#    #+#             */
/*   Updated: 2025/12/24 22:25:14 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_philo_action(t_philo *philo, char *action)
{
	long long	time_start;

	time_start = getting_time() - philo->data->time_start;
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("%lld %d %s\n", time_start, philo->id, action);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	philo_take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->fork[philo->fork_left]);
	print_philo_action(philo, "has token a fork");
	pthread_mutex_lock(&philo->data->fork[philo->fork_right]);
	print_philo_action(philo, "has token a fork");
}

void	philo_eat(t_philo *philo)
{
	print_philo_action(philo, "is eating");
	pthread_mutex_lock(&philo->data->eat_mutex);
	philo->last_eat = getting_time();
	pthread_mutex_unlock(&philo->data->eat_mutex);
	usleep(philo->data->eat_time * 1000);
	philo->n_eat++;
}

void	philo_put_fork(t_philo *philo)
{
	pthread_mutex_unlock(&philo->data->fork[philo->fork_left]);
	pthread_mutex_unlock(&philo->data->fork[philo->fork_right]);
}

void	philo_sleep(t_philo *philo)
{
	print_philo_action(philo, "is sleeping");
	usleep(philo->data->sleep_time * 1000);
}
