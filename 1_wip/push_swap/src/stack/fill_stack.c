/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:47:23 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/15 12:44:50 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_stack_fail(char **strs, int index, t_ps *data)
{
	free(strs[index]);
	free(strs);
	error(data);
}

void	fill_stack(int argc, char **argv, t_ps *data)
{
	char	**args;
	int		numbers_count;

	numbers_count = data->capacity;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			error(data);
		while (--numbers_count >= 0)
		{
			if (!push(data, &data->a, ft_atoi(args[numbers_count])))
				fill_stack_fail(args, numbers_count, data);
			free(args[numbers_count]);
		}
		free(args);
	}
	else
		while (numbers_count > 0)
			if (!push(data, &data->a, ft_atoi(argv[numbers_count--])))
				error(data);
}
