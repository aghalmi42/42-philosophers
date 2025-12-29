/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 21:59:06 by aghalmi           #+#    #+#             */
/*   Updated: 2025/12/29 22:02:29 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	free_semaphore(t_data *data)
{
	if (data->fork)
	{
		sem_close(data->fork);
		sem_unlink("/fork");
	}
	if (data->print_sem)
	{
		sem_close(data->print_sem);
		sem_unlink("/print");
	}
	if (data->stop_sem)
	{
		sem_close(data->stop_sem);
		sem_unlink("/stop");
	}
	if (data->eat_sem)
	{
		sem_close(data->eat_sem);
		sem_unlink("/eat");
	}
}

void	free_all(t_data *data)
{
	free_semaphore(data);
	if (data->philo)
		free(data->philo);
}
