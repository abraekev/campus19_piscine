/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_lens.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:58:41 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/15 08:21:54 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ftpf_set_i_len(t_printf *d)
{
	if (!d->insert)
		d->i_len = 0;
	else
		d->i_len = ft_strlen(d->insert);
	if (!d->i_len && d->cspec == 'c')
		d->i_len = 1;
}

void	ftpf_set_s_len_and_nullprotect(t_printf *d)
{
	if (!d->i_len && d->insert == NULL)
		ftpf_get_empty_str(d);
	d->s_len = d->s_len - d->f_len + d->i_len;
}

void	ftpf_set_lengths(t_printf *d)
{
	ftpf_set_i_len(d);
	ftpf_set_s_len_and_nullprotect(d);
}
