/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 22:10:53 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/15 12:47:59 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ops_push_from_to(t_ps *data, t_stack *x, t_stack *y)
{
	if (x->size < 1)
		return ;
	if (!push(data, y, x->stack[x->top]))
		error(data);
	pop(data, x);
}

void	pa(t_ps *data)
{
	ops_push_from_to(data, &data->b, &data->a);
	if (data->log_ops)
		log_ops(data, PA);
}

void	pb(t_ps *data)
{
	ops_push_from_to(data, &data->a, &data->b);
	if (data->log_ops)
		log_ops(data, PB);
}
