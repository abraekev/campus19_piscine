/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_basic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:56:22 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/15 12:47:32 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_ps *data, t_stack *stack, int value)
{
	int	old_size;
	int	new_size;
	int	i;

	if (is_full(data, stack))
		return (0);
	old_size = stack->size;
	new_size = old_size + 1;
	i = old_size;
	while (--i >= stack->top)
		stack->stack[i + 1] = stack->stack[i];
	stack->stack[stack->top] = value;
	stack->size = new_size;
	stack->bottom = next_up(stack, stack->top);
	return (1);
}

int	pop(t_ps *data, t_stack *stack)
{
	int	result;
	int	i;

	if (is_empty(stack))
		error(data);
	result = stack->stack[stack->top];
	i = stack->top;
	while (i < stack->size)
	{
		stack->stack[i] = stack->stack[i + 1];
		i++;
	}
	stack->size--;
	if (stack->top == stack->size)
		stack->top = 0;
	stack->bottom = next_up(stack, stack->top);
	return (result);
}
