/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 22:22:36 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/11 22:35:28 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Create a function that returns 1 if the string given as a parameter contains only
digits, and 0 if it contains any other character.
*/

#include <unistd.h>
//#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	while (*str != '\0')
	{
		if (!((*str >= '0' && *str <= '9')))
			return (0);
		str++;
	}
	return (1);
}

/*
int     main(void)
{
        char    *str1 = "abcd";
        char    *str2 = "1242";
        
        printf("string: \"%s\" is: %d",str1,ft_str_is_numeric(str1));
        printf("string: \"%s\" is: %d",str2,ft_str_is_numeric(str2));

        return (0);
}
*/
