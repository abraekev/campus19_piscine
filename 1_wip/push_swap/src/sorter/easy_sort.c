/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:31:43 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/15 12:27:13 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_top_b(t_ps *data, t_chunk *chunk)
{
	sb(data);
	pa(data);
	if (value(&data->b, 1) == value(&data->a, 1) - 1)
	{
		pa(data);
		chunk->size--;
	}
}

static void	handle_bottom_a(t_ps *data, t_chunk *chunk)
{
	rra(data);
	rra(data);
	sa(data);
	if (value(&data->a, 1) == value(&data->a, 2) - 1)
		chunk->size--;
	else
		ra(data);
}

static void	handle_bottom_b(t_ps *data, t_chunk *chunk)
{
	rrb(data);
	rrb(data);
	pa(data);
	if (value(&data->b, 1) == value(&data->a, 1) - 1)
	{
		pa(data);
		chunk->size--;
	}
	else
		rb(data);
}

static void	easy_sort_second(t_ps *data, t_chunk *chunk)
{
	if (chunk->loc == TOP_B)
		handle_top_b(data, chunk);
	else if (chunk->loc == BOTTOM_A)
		handle_bottom_a(data, chunk);
	else if (chunk->loc == BOTTOM_B)
		handle_bottom_b(data, chunk);
	chunk->size--;
}

void	easy_sort(t_ps *data, t_chunk *chunk)
{
	while (chunk->loc != TOP_A && chunk->size)
	{
		if (value(&data->a, 1) == chunk_value(data, chunk, 1) + 1
			&& chunk->size > 0)
			chunk_sort_one(data, chunk);
		else if (value(&data->a, 1) == chunk_value(data, chunk, 2) + 1
			&& chunk->size > 1)
			easy_sort_second(data, chunk);
		else
			break ;
	}
}
