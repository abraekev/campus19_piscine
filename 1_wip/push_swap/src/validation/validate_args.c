/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:52:07 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/15 14:59:44 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	validate_single_argument(char *arg, int *numbers_count)
{
	char	**numbers_string;

	if (!*arg)
		error(NULL);
	numbers_string = ft_split(arg, ' ');
	*numbers_count = 0;
	while (*(numbers_string + *numbers_count))
	{
		if (!is_valid_int_string(*(numbers_string + *numbers_count)))
		{
			free_str_array(numbers_string);
			error(NULL);
		}
		(*numbers_count)++;
	}
	free_str_array(numbers_string);
}

static void	validate_multiple_arguments(char **argv, int *numbers_count)
{
	while (*argv)
	{
		if (!is_valid_int_string(*argv))
			error(NULL);
		argv++;
		(*numbers_count)++;
	}
}

int	validate_arguments(int argc, char **argv)
{
	int	numbers_count;

	if (argc < 2 || !argv)
		error(NULL);
	if (argc == 2)
		validate_single_argument(argv[1], &numbers_count);
	else
		validate_multiple_arguments(argv + 1, &numbers_count);
	return (numbers_count);
}
