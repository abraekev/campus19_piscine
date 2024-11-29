/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_duplicate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 19:14:38 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/15 14:29:10 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*init_compare(t_ps *data)
{
	int	*compare;

	compare = malloc((data->capacity) * sizeof(int));
	if (!compare)
		error(data);
	return (compare);
}

void	duplicate_check(t_ps *data, t_stack *stack)
{
	int	*compare;
	int	compare_size;
	int	i;
	int	j;

	compare = init_compare(data);
	i = stack->bottom;
	compare_size = 0;
	while (1)
	{
		j = 0;
		while (j < compare_size)
		{
			if (stack->stack[i] == compare[j++])
			{
				free(compare);
				error(data);
			}
		}
		compare[compare_size++] = stack->stack[i];
		i = next_down(stack, i);
		if (i == stack->bottom)
			break ;
	}
	free(compare);
}
