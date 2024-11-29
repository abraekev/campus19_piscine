/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapper_rank.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:41:22 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/15 12:04:36 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	replace_buffer(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size)
	{
		j = 0;
		while (j < stack->size)
		{
			if (stack->stack[i] == stack->mapper[j])
			{
				stack->stack[i] = (j + 1);
				break ;
			}
			j++;
		}
		i++;
	}
}

int	create_mapper(t_stack *stack)
{
	int	index;
	int	i;
	int	j;

	i = 0;
	stack->mapper = malloc(sizeof(int) * stack->size);
	if (!stack->mapper)
		return (0);
	while (i < stack->size)
	{
		index = 0;
		j = 0;
		while (j < stack->size)
		{
			if (i != j && stack->stack[i] > stack->stack[j])
				index++;
			j++;
		}
		stack->mapper[index] = stack->stack[i++];
	}
	replace_buffer(stack);
	return (1);
}
