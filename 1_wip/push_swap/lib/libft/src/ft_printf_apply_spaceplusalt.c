/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_apply_spaceplusalt.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:58:41 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/15 08:22:40 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ftpf_add_prefix(t_printf *d, char *prefix)
{
	char	*out;
	char	*s;

	s = d->insert;
	if (!s)
		return (NULL);
	if (*s == '-')
		return (s);
	out = ft_strjoin(prefix, s);
	free(s);
	if (!out)
		return (NULL);
	return (out);
}

char	*ftpf_apply_spaceplus(t_printf *d, t_pf_flags f)
{
	char	*s;

	s = d->insert;
	if (!s)
		return (NULL);
	if (f.pref_space && !f.pref_plus)
		return (ftpf_add_prefix(d, " "));
	if (f.pref_plus)
		return (ftpf_add_prefix(d, "+"));
	return (s);
}

char	*ftpf_apply_altprint(t_printf *d, t_pf_flags f)
{
	char	*s;

	s = d->insert;
	if (!s)
		return (NULL);
	if (!f.alt_print || (f.alt_print && !ft_strncmp(s, "0", d->i_len + 1)))
		return (s);
	if (f.cspec == 'x')
		return (ftpf_add_prefix(d, "0x"));
	else
		return (ftpf_add_prefix(d, "0X"));
}
