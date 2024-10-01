/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:52:07 by abraekev          #+#    #+#             */
/*   Updated: 2024/09/30 15:37:38 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void create_stack(int argc, char **argv, Stack **stack)
{
    argc--;
    init_stack(argc, stack);
    while (argc > 0)
        push(*stack, ft_atoi(argv[argc--]));
}

int main(int argc, char **argv)
{
    Stack *a;
    Stack *b;
    int stack_capacity;

    b = NULL;
    validate_arguments(argc, argv);
    create_stack(argc, argv, &a);
    check_duplicates(a);
}
