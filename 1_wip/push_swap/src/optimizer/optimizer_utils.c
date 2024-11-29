/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:12:25 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/15 09:40:44 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

enum e_op	neutral_op(enum e_op op)
{
	if (op == PA)
		return (PB);
	if (op == PB)
		return (PA);
	if (op == RA)
		return (RRA);
	if (op == RB)
		return (RRB);
	if (op == RRA)
		return (RA);
	if (op == RRB)
		return (RB);
	if (op == SA)
		return (SA);
	if (op == SB)
		return (SB);
	if (op == RR)
		return (RRR);
	return (NULL_OP);
}

int	op_on_same_stack(enum e_op ref, enum e_op to_check)
{
	if (ref == PA || ref == PB || ref == RR || ref == RRR)
		return (1);
	if (to_check == PA || to_check == PB || to_check == RR || to_check == RRR)
		return (1);
	else if (ref == RA || ref == RRA || ref == SA)
		return (to_check == RA || to_check == RRA || to_check == SA);
	else if (ref == RB || ref == RRB || ref == SB)
		return (to_check == RB || to_check == RRB || to_check == SB);
	return (0);
}

enum e_op	child_op(enum e_op first, enum e_op second)
{
	if ((first == RA && second == RB) || (first == RB && second == RA))
		return (RR);
	else if ((first == RRA && second == RRB) || (first == RRB && second == RRA))
		return (RRR);
	else if ((first == SA && second == SB) || (first == SB && second == SA))
		return (SS);
	else
		return (NULL_OP);
}

void	remove_op(t_list *to_delete)
{
	to_delete->prev->next = to_delete->next;
	if (to_delete->next)
		to_delete->next->prev = to_delete->prev;
	ft_lstdelone(to_delete, NULL);
}
