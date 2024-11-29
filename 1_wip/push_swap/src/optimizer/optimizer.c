/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:04:50 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/15 12:16:41 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	eliminate_neutral_op(t_list *op_list)
{
	t_list		*ref;
	t_list		*cmp;
	enum e_op	op_neutral;

	ref = op_list->next;
	while (ref && ref->next)
	{
		op_neutral = neutral_op(op_from(ref));
		if (op_neutral)
		{
			cmp = ref->next;
			while (!op_on_same_stack(op_from(ref), op_from(cmp))
				&& op_from(cmp) != op_neutral && cmp->next)
				cmp = cmp->next;
			if (ref->prev && op_from(cmp) == op_neutral)
			{
				ref = ref->prev;
				remove_op(ref->next);
				remove_op(cmp);
				continue ;
			}
		}
		ref = ref->next;
	}
}

static void	merge_op(t_list *op_list)
{
	t_list		*reader;
	enum e_op	child;

	reader = op_list;
	while (reader && reader->next)
	{
		child = child_op(op_from(reader), op_from(reader->next));
		if (child)
		{
			remove_op(reader->next);
			reader->content = (void *)(uintptr_t)child;
		}
		reader = reader->next;
	}
}

void	optimize_ops(t_ps *data)
{
	if (!data->ops)
		return ;
	eliminate_neutral_op(data->ops);
	merge_op(data->ops);
}
