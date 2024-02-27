/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:26:59 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/27 13:04:29 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	no_arg(char **argv)
{
	char	buf;

	while (read(0, &buf, 1) != 0)
	{
		if (errno == 0)
			ft_putchar(buf);
		else
		{
			ft_error(basename(argv[0]));
			ft_error(": stdin: ");
			ft_errno(-1);
			ft_error("\n");
		}
	}
}

void	cat_error(char **argv, int i)
{
	if (errno != 0)
	{
		ft_error(basename(argv[0]));
		ft_error(": ");
		ft_error(argv[i]);
		ft_error(": ");
		ft_errno(-1);
		ft_error("\n");
	}
}

int	main(int argc, char **argv)
{
	int		i;

	if (argc == 1)
	{
		no_arg(argv);
		return (0);
	}
	i = 0;
	while (++i < argc)
	{
		if (ft_cat(argv[i]) == 0)
			cat_error(argv, i);
	}
	return (0);
}
