/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:04:36 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/10 11:57:33 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three_top_a(t_ps *data, t_chunk *chunk, t_stack *stack,
		int max)
{
	if (stack->stack[stack->top] == max)
	{
		sa(data);
		ra(data);
		sa(data);
		rra(data);
	}
	else if (stack->stack[next_down(stack, stack->top)] == max)
	{
		ra(data);
		sa(data);
		rra(data);
	}
	chunk->loc = TOP_A;
	chunk->size -= 1;
	chunk_sort_two(data, chunk);
}

static void	sort_three_bottom_a(t_ps *data, t_chunk *chunk, t_stack *stack,
		int max)
{
	rra(data);
	rra(data);
	if (stack->stack[stack->top] == max)
	{
		sa(data);
		rra(data);
	}
	else if (stack->stack[next_down(stack, stack->top)] == max)
		rra(data);
	else
	{
		pb(data);
		rra(data);
		sa(data);
		pa(data);
	}
	chunk->loc = TOP_A;
	chunk->size -= 1;
	chunk_sort_two(data, chunk);
}

static void	sort_three_top_b(t_ps *data, t_chunk *chunk, t_stack *stack,
		int max)
{
	pa(data);
	if (stack->stack[stack->top] == max)
	{
		pa(data);
		sa(data);
	}
	else if (stack->stack[next_down(stack, stack->top)] == max)
	{
		sb(data);
		pa(data);
		sa(data);
	}
	else
		pa(data);
	pa(data);
	chunk->loc = TOP_A;
	chunk->size -= 1;
	chunk_sort_two(data, chunk);
}

static void	sort_three_bottom_b(t_ps *data, t_chunk *chunk, t_stack *stack,
		int max)
{
	rrb(data);
	rrb(data);
	if (stack->stack[stack->top] == max)
	{
		pa(data);
		rrb(data);
	}
	else if (stack->stack[next_down(stack, stack->top)] == max)
	{
		sb(data);
		pa(data);
		rrb(data);
	}
	else
	{
		rrb(data);
		pa(data);
	}
	chunk->loc = TOP_B;
	chunk->size -= 1;
	chunk_sort_two(data, chunk);
}

void	chunk_sort_three(t_ps *data, t_chunk *chunk)
{
	t_stack	*stack;
	int		max;

	stack = loc_to_stack(data, chunk->loc);
	max = chunk_max_value(data, chunk);
	if (chunk->loc == TOP_A)
		sort_three_top_a(data, chunk, stack, max);
	else if (chunk->loc == BOTTOM_A)
		sort_three_bottom_a(data, chunk, stack, max);
	else if (chunk->loc == TOP_B)
		sort_three_top_b(data, chunk, stack, max);
	else if (chunk->loc == BOTTOM_B)
		sort_three_bottom_b(data, chunk, stack, max);
}
