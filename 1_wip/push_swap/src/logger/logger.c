/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:55:54 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/15 11:52:05 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*get_op_str(t_op op)
{
	char	*strings[12];

	strings[0] = "zero op";
	strings[1] = "pa";
	strings[2] = "pb";
	strings[3] = "sa";
	strings[4] = "sb";
	strings[5] = "ss";
	strings[6] = "ra";
	strings[7] = "rb";
	strings[8] = "rr";
	strings[9] = "rra";
	strings[10] = "rrb";
	strings[11] = "rrr";
	if (op < 0 || op > RRR)
		return ("Invalid op");
	return (strings[op]);
}

static void	print_lst_item(void *ptr)
{
	t_op	op;

	op = (t_op)(uintptr_t)ptr;
	ft_printf(1, "%s\n", get_op_str(op));
}

void	log_ops(t_ps *data, t_op op)
{
	t_list	*new;

	new = ft_lstnew((void *)(uintptr_t)op);
	if (!new)
		error(data);
	ft_lstadd_back(&data->ops, new);
}

void	print_log(t_ps *data)
{
	ft_lstiter(data->ops, print_lst_item);
}

t_op	op_from(t_list *node)
{
	return ((t_op)(uintptr_t)node->content);
}
