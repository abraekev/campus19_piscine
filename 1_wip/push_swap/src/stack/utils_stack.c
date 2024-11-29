/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:59:02 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/15 12:48:15 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_ps *data)
{
	int	i;
	int	rank;

	i = data->a.top;
	rank = 1;
	while (rank <= data->a.size)
	{
		if (data->a.stack[i] != rank)
			return (0);
		rank++;
		i = next_down(&data->a, i);
	}
	return (1);
}

int	is_full(t_ps *data, t_stack *stack)
{
	return (stack->size == data->capacity);
}

int	is_empty(t_stack *stack)
{
	return (stack->size == 0);
}

void	print_stack(t_stack *stack)
{
	int	index;

	ft_printf(1, "top %d\n", stack->top);
	ft_printf(1, "bot %d\n", stack->bottom);
	ft_printf(1, "siz %d\n", stack->size);
	ft_printf(1, "TOP======\n");
	if (is_empty(stack))
	{
		ft_printf(1, "Stack is empty\n");
		return ;
	}
	index = stack->top;
	while (1)
	{
		ft_printf(1, "[%d]\t%d\n", index, stack->stack[index]);
		index = next_down(stack, index);
		if (index == stack->top)
			break ;
	}
	ft_printf(1, "BOT======\n");
}

void	free_stack(t_stack *stack)
{
	if (!stack)
		return ;
	if (stack->stack)
		free(stack->stack);
	if (stack->mapper)
		free(stack->mapper);
	stack->stack = NULL;
	stack->mapper = NULL;
	stack->top = 0;
	stack->size = 0;
}
