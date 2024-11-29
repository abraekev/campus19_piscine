/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 09:39:36 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/15 14:26:00 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//	HEADERS
/******************************************************************************/

# include "libft.h"

//	MACROS
/******************************************************************************/

//	STRUCTS & ENUMS
/******************************************************************************/

typedef enum e_op
{
	NULL_OP,
	PA,
	PB,
	SA,
	SB,
	SS,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
}				t_op;

typedef enum e_location
{
	TOP_A,
	BOTTOM_A,
	TOP_B,
	BOTTOM_B
}				t_location;

typedef struct s_chunk
{
	t_location	loc;
	int			size;
}				t_chunk;

typedef struct s_split_destination
{
	t_chunk		min;
	t_chunk		mid;
	t_chunk		max;
}				t_destination;

typedef struct s_circular_array_stack
{
	int			*stack;
	int			*mapper;
	int			top;
	int			bottom;
	int			size;
}				t_stack;

typedef struct s_push_swap_data
{
	t_stack		a;
	t_stack		b;
	t_list		*ops;
	int			capacity;
	int			log_ops;
}				t_ps;

//	DEFINITIONS
/******************************************************************************/

// logger
void			log_ops(t_ps *data, t_op op);
void			print_log(t_ps *data);
t_op			op_from(t_list *node);

// mapper
int				create_mapper(t_stack *stack);

// optimizer
void			remove_op(t_list *to_delete);
enum e_op		child_op(enum e_op first, enum e_op second);
int				op_on_same_stack(enum e_op ref, enum e_op to_check);
enum e_op		neutral_op(enum e_op op);
void			optimize_ops(t_ps *data);

// push_swap
int				main(int argc, char **argv);

// sorter
int				a_partly_sort(t_ps *data, int from);
void			chunk_sort(t_ps *data);
void			chunk_to_the_top(t_ps *data, t_chunk *chunk);
int				chunk_value(t_ps *data, t_chunk *chunk, int n);
int				chunk_max_value(t_ps *data, t_chunk *chunk);
void			chunk_sort_one(t_ps *data, t_chunk *chunk);
void			chunk_sort_three(t_ps *data, t_chunk *chunk);
void			chunk_sort_two(t_ps *data, t_chunk *chunk);
void			chunk_split(t_ps *data, t_chunk *chunk, t_destination *dest);
void			easy_sort(t_ps *data, t_chunk *chunk);
int				is_edgecase(t_ps *data);
t_stack			*loc_to_stack(t_ps *data, t_location loc);
int				move_from_to(t_ps *data, t_location from, t_location to);
void			sort(t_ps *data);
void			sort_edgecase(t_ps *data);
void			sort_three(t_ps *data);
void			split_max_reduction(t_ps *data, t_chunk *max);

// stack
void			fill_stack(int argc, char **argv, t_ps *data);
void			free_stack(t_stack *stack);
int				is_empty(t_stack *stack);
int				is_full(t_ps *data, t_stack *stack);
int				is_sorted(t_ps *data);
void			init_stack(t_ps *data, t_stack *stack, int size);
int				next_down(t_stack *stack, int index);
int				pop(t_ps *data, t_stack *stack);
int				next_up(t_stack *stack, int index);
void			print_stack(t_stack *stack);
int				push(t_ps *data, t_stack *stack, int value);
int				value(t_stack *stack, int rank);
void			pa(t_ps *data);
void			pb(t_ps *data);
void			ra(t_ps *data);
void			rb(t_ps *data);
void			rr(t_ps *data);
void			rra(t_ps *data);
void			rrb(t_ps *data);
void			rrr(t_ps *data);
void			sa(t_ps *data);
void			sb(t_ps *data);
void			ss(t_ps *data);

// utils
void			error(t_ps *data);
void			free_data(t_ps *data);
void			free_str_array(char **array);
void			init_data(int capacity, int argc, char **argv, t_ps *data);

// validation
int				validate_arguments(int argc, char **argv);
int				is_valid_int_string(const char *str);
void			duplicate_check(t_ps *data, t_stack *stack);

#endif /*PUSH_SWAP_H*/