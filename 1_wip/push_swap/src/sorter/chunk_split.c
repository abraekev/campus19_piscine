/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:57:22 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/15 14:25:58 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	innit_size(t_chunk *min, t_chunk *mid, t_chunk *max)
{
	min->size = 0;
	mid->size = 0;
	max->size = 0;
}

static void	set_split_loc(t_location loc, t_chunk *min, t_chunk *mid,
		t_chunk *max)
{
	if (loc == TOP_A)
	{
		min->loc = BOTTOM_B;
		mid->loc = TOP_B;
		max->loc = BOTTOM_A;
	}
	else if (loc == BOTTOM_A)
	{
		min->loc = BOTTOM_B;
		mid->loc = TOP_B;
		max->loc = TOP_A;
	}
	else if (loc == TOP_B)
	{
		min->loc = BOTTOM_B;
		mid->loc = BOTTOM_A;
		max->loc = TOP_A;
	}
	else if (loc == BOTTOM_B)
	{
		min->loc = TOP_B;
		mid->loc = BOTTOM_A;
		max->loc = TOP_A;
	}
}

static void	set_third_pivots(t_location loc, int chunk_size, int *pivot_1,
		int *pivot_2)
{
	*pivot_2 = chunk_size / 3;
	if (loc == TOP_A || loc == BOTTOM_A)
		*pivot_1 = 2 * chunk_size / 3;
	if (loc == TOP_B || loc == BOTTOM_B)
		*pivot_1 = chunk_size / 2;
	if ((loc == TOP_A || loc == BOTTOM_A) && chunk_size < 15)
		*pivot_1 = chunk_size;
	if (loc == BOTTOM_B && chunk_size < 8)
		*pivot_2 = chunk_size / 2;
}

void	chunk_split(t_ps *data, t_chunk *chunk, t_destination *dest)
{
	int	pivot_1;
	int	pivot_2;
	int	max_value;
	int	next_value;

	innit_size(&dest->min, &dest->mid, &dest->max);
	set_split_loc(chunk->loc, &dest->min, &dest->mid, &dest->max);
	set_third_pivots(chunk->loc, chunk->size, &pivot_1, &pivot_2);
	max_value = chunk_max_value(data, chunk);
	while (chunk->size--)
	{
		next_value = chunk_value(data, chunk, 1);
		if (next_value > max_value - pivot_2)
		{
			dest->max.size += move_from_to(data, chunk->loc, dest->max.loc);
			split_max_reduction(data, &dest->max);
			if (a_partly_sort(data, 1) && chunk->size)
				easy_sort(data, chunk);
		}
		else if (next_value > max_value - pivot_1)
			dest->mid.size += move_from_to(data, chunk->loc, dest->mid.loc);
		else
			dest->min.size += move_from_to(data, chunk->loc, dest->min.loc);
	}
}
