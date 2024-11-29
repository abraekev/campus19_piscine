/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:10:51 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/14 10:42:55 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_data(int capacity, int argc, char **argv, t_ps *data)
{
	data->capacity = capacity;
	data->log_ops = 1;
	data->ops = NULL;
	init_stack(data, &data->a, capacity);
	init_stack(data, &data->b, capacity);
	fill_stack(argc, argv, data);
	duplicate_check(data, &data->a);
	create_mapper(&data->a);
}
