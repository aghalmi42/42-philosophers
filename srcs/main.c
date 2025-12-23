/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 20:01:29 by aghalmi           #+#    #+#             */
/*   Updated: 2025/12/23 21:07:30 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (parsing_argument(ac, av, &data))
		return (1);
	if (!init(&data))
	{
		printf("ERROR\nFail init");
		return (1);
	}
	printf("%d\n", data.n_philo);
	printf("%d\n", data.die_time);
	printf("%lld\n", data.time_start);
	return (0);
}
