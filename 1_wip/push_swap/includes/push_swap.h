/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 09:39:36 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/02 12:29:51 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

//	HEADERS
/******************************************************************************/

#include "libft.h"

//	MACROS
/******************************************************************************/

//	STRUCTS & ENUMS
/******************************************************************************/

typedef struct s_circular_array_stack
{
	int *buffer;
	int *mapper;
	int top;
	int bottom;
	int size;
	int capacity;
} Stack;

//	DEFINITIONS
/******************************************************************************/

// exist_utils
void ft_exit(char *errorMessage, int errorCode);
void error_free(char *error_message, void (*free)(void *), ...);

// malloc_utils
void free_str_array(char **array);

// mappers
int create_mapper(Stack *stack);

// stack_ops
void ops_swap(Stack *stack);
void ops_swap_both(Stack *x, Stack *y);
void ops_push_from_to(Stack *x, Stack *y);
void ops_rotate(Stack *stack);
void ops_reverse_rotate(Stack *stack);
void ops_rotate_both(Stack *x, Stack *y);
void ops_reverse_rotate_both(Stack *x, Stack *y);

// stack_utils
Stack *init_stack(int capacity);
int is_full(Stack *stack);
int is_empty(Stack *stack);
void push(Stack *stack, int value);
int pop(Stack *stack);
int peek(Stack *stack);
void free_stack(void *ptr);
void print_stack(Stack *stack);
int next(Stack *stack, int index);
int previous(Stack *stack, int index);
void create_stacks(int argc, char **argv, Stack **a, Stack **b);

// validation
int validate_arguments(int argc, char **argv);
int is_valid_int_string(const char *str);
int has_duplicates(Stack *stack);

#endif /*PUSH_SWAP_H*/