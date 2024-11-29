/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:50:18 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/15 12:20:28 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_from_top_b(t_ps *data, t_location to)
{
	if (to == TOP_A)
		pa(data);
	else if (to == BOTTOM_B)
		rb(data);
	else if (to == BOTTOM_A)
	{
		pa(data);
		ra(data);
	}
}

static void	move_from_top_a(t_ps *data, t_location to)
{
	if (to == TOP_B)
		pb(data);
	else if (to == BOTTOM_A)
		ra(data);
	else if (to == BOTTOM_B)
	{
		pb(data);
		rb(data);
	}
}

static void	move_from_bottom_a(t_ps *data, t_location to)
{
	if (to == TOP_A)
		rra(data);
	else if (to == TOP_B)
	{
		rra(data);
		pb(data);
	}
	else if (to == BOTTOM_B)
	{
		rra(data);
		pb(data);
		rb(data);
	}
}

static void	move_from_bottom_b(t_ps *data, t_location to)
{
	if (to == TOP_B)
		rrb(data);
	else if (to == TOP_A)
	{
		rrb(data);
		pa(data);
	}
	else if (to == BOTTOM_A)
	{
		rrb(data);
		pa(data);
		ra(data);
	}
}

int	move_from_to(t_ps *data, t_location from, t_location to)
{
	if (from == TOP_A)
		move_from_top_a(data, to);
	else if (from == TOP_B)
		move_from_top_b(data, to);
	else if (from == BOTTOM_A)
		move_from_bottom_a(data, to);
	else if (from == BOTTOM_B)
		move_from_bottom_b(data, to);
	return (1);
}
