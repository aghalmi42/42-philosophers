/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 22:03:56 by aghalmi           #+#    #+#             */
/*   Updated: 2025/12/24 22:09:26 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_think(t_philo *philo)
{
	print_philo_action(philo, "is thinking");
}

void	*philo_routine(void *av)
{
	t_philo	*philo;

	philo = (t_philo *)av;
	while (!philo->data->stop)
	{
		philo_take_fork(philo);
		philo_eat(philo);
		philo_put_fork(philo);
		philo_sleep(philo);
	}
	return (NULL);
}
