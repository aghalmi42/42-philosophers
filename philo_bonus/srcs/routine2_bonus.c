/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 19:37:03 by aghalmi           #+#    #+#             */
/*   Updated: 2025/12/29 21:30:56 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	philo_think(t_philo *philo)
{
	print_philo_action(philo, "is thinking");
}

void	philo_routine(t_philo *philo)
{
	pthread_t	check;

	sem_wait(philo->data->eat_sem);
	philo->last_eat = getting_time();
	sem_post(philo->data->eat_sem);
	pthread_create(&check, NULL, check_philo_dead_eat, philo);
	pthread_detach(check);
	if (philo->id % 2 == 0)
		usleep(philo->data->eat_time * 500);
	while (1)
	{
		philo_take_fork(philo);
		philo_eat(philo);
		philo_put_fork(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
}
