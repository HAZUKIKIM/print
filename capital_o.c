/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capital_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 11:52:38 by hmiyake           #+#    #+#             */
/*   Updated: 2018/08/01 14:16:05 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	specifier_capital_o(va_list ap, char *save_f, int *w_n_p)
{
	uintmax_t	num;
	int			i;

	num = (unsigned long)va_arg(ap, uintmax_t);
	if (count5(num, w_n_p) >= w_n_p[0] && count5(num, w_n_p) >= w_n_p[1])
		i = count5(num, w_n_p) + o_c_is_biggest(save_f, w_n_p, num);
	else if (w_n_p[1] > count5(num, w_n_p) && w_n_p[1] >= w_n_p[0])
		i = count5(num, w_n_p) + o_p_is_biggest(save_f, w_n_p, num);
	else if (w_n_p[0] > count5(num, w_n_p) && w_n_p[0] > w_n_p[1]
			&& w_n_p[1] >= count5(num, w_n_p) && flag_check(save_f, '-'))
		i = count5(num, w_n_p)
			+ o_wpc_with_m(save_f, w_n_p, num);
	else if (w_n_p[0] > count5(num, w_n_p) && w_n_p[0] > w_n_p[1]
			&& w_n_p[1] >= count5(num, w_n_p))
		i = count5(num, w_n_p) + o_wpc(save_f, w_n_p, num);
	else if (w_n_p[0] > count5(num, w_n_p) && w_n_p[0] > w_n_p[1]
			&& w_n_p[1] <= count5(num, w_n_p) && flag_check(save_f, '-'))
		i = count5(num, w_n_p) + o_wcp_with_m(save_f, w_n_p, num);
	else
		i = count5(num, w_n_p) + o_wcp(save_f, w_n_p, num);
	return (i);
}
