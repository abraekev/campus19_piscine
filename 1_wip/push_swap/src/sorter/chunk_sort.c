/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:05:36 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/15 14:25:58 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rec_chunk_sort(t_ps *data, t_chunk *chunk)
{
	t_destination	dest;

	chunk_to_the_top(data, chunk);
	easy_sort(data, chunk);
	if (chunk->size <= 3)
	{
		if (chunk->size == 3)
			chunk_sort_three(data, chunk);
		else if (chunk->size == 2)
			chunk_sort_two(data, chunk);
		else if (chunk->size == 1)
			chunk_sort_one(data, chunk);
		return ;
	}
	chunk_split(data, chunk, &dest);
	rec_chunk_sort(data, &dest.max);
	rec_chunk_sort(data, &dest.mid);
	rec_chunk_sort(data, &dest.min);
}

void	chunk_sort(t_ps *data)
{
	t_chunk	chunk;

	chunk.loc = TOP_A;
	chunk.size = data->a.size;
	rec_chunk_sort(data, &chunk);
}

void	chunk_sort_one(t_ps *data, t_chunk *chunk)
{
	if (chunk->loc == BOTTOM_A || chunk->loc == BOTTOM_B || chunk->loc == TOP_B)
		move_from_to(data, chunk->loc, TOP_A);
	chunk->size -= 1;
}

void	chunk_sort_two(t_ps *data, t_chunk *chunk)
{
	if (chunk->loc == BOTTOM_A || chunk->loc == BOTTOM_B || chunk->loc == TOP_B)
	{
		move_from_to(data, chunk->loc, TOP_A);
		move_from_to(data, chunk->loc, TOP_A);
	}
	if (value(&data->a, 1) > value(&data->a, 2))
		sa(data);
	chunk->size -= 2;
}
