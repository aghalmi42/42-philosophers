/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 19:26:53 by aghalmi           #+#    #+#             */
/*   Updated: 2025/12/29 19:36:43 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	print_philo_action(t_philo *philo, char *action)
{
	long long	time_start;

	sem_wait(philo->data->print_sem);
	time_start = getting_time() - philo->data->time_start;
	printf("%lld %d %s\n", time_start, philo->id, action);
	sem_post(philo->data->print_sem);
}

void	philo_take_fork(t_philo *philo)
{
	sem_wait(philo->data->fork);
	print_philo_action(philo, "has taken a fork");
	sem_wait(philo->data->fork);
	print_philo_action(philo, "has taken a fork");
}

void	philo_eat(t_philo *philo)
{
	print_philo_action(philo, "is eating");
	sem_wait(philo->data->eat_sem);
	philo->last_eat = getting_time();
	philo->n_eat++;
	sem_post(philo->data->eat_sem);
	usleep(philo->data->eat_time * 1000);
}

void	philo_put_fork(t_philo *philo)
{
	sem_post(philo->data->fork);
	sem_post(philo->data->fork);
}

void	philo_sleep(t_philo *philo)
{
	print_philo_action(philo, "is sleeping");
	usleep(philo->data->sleep_time * 1000);
}
