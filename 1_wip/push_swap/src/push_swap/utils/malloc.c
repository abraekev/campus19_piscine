/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:04:41 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/02 18:04:43 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_str_array(char **array)
{
    int i;

    i = 0;
    while (array[i])
    {
        free(array[i]);
        i++;
    }
    free(array);
}