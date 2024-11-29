/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edgecase.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:27:16 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/15 12:22:52 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_reverse_sorted(t_ps *data)
{
	int	i;
	int	rank;

	i = data->a.top;
	rank = data->a.size;
	while (rank >= 1)
	{
		if (data->a.stack[i] != rank)
			return (0);
		rank--;
		i = next_down(&data->a, i);
	}
	return (1);
}

int	is_edgecase(t_ps *data)
{
	return ((data->capacity == 9 || data->capacity == 12)
		&& is_reverse_sorted(data));
}

void	sort_edgecase(t_ps *data)
{
	while (data->a.size > 3)
		pb(data);
	sort_three(data);
	while (data->b.size > 0)
	{
		pa(data);
		ra(data);
	}
}
