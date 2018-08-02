/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capital_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 19:39:54 by hmiyake           #+#    #+#             */
/*   Updated: 2018/08/01 14:40:00 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	specifier_capital_c(va_list ap, char *save_f, int *w_n_p)
{
	wint_t	w;
	int		i;

	w = 0;
	i = 0;
	if (flag_check(save_f, '-'))
		i = minus_n_l(ap, w, w_n_p, i);
	else
		i = no_minus_n_l(ap, w, w_n_p, i);
	return (i);
}
