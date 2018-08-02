/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capital_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 17:40:22 by hmiyake           #+#    #+#             */
/*   Updated: 2018/07/31 17:47:38 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	specifier_capital_d(va_list ap, char *save_f, int *w_n_p)
{
	intmax_t	num;
	int			i;

	num = (long)va_arg(ap, intmax_t);
	if (count6(num, w_n_p) >= w_n_p[0] && count6(num, w_n_p) >= w_n_p[1])
		i = count6(num, w_n_p) + c_is_biggest(save_f, w_n_p, num);
	else if (w_n_p[1] > count6(num, w_n_p) && w_n_p[1] >= w_n_p[0])
		i = count6(num, w_n_p) + p_is_biggest(save_f, w_n_p, num);
	else if (w_n_p[0] > count6(num, w_n_p) && w_n_p[0] > w_n_p[1]
			&& w_n_p[1] >= count6(num, w_n_p) && flag_check(save_f, '-'))
		i = count6(num, w_n_p)
			+ d_wpc_with_m(save_f, w_n_p, num);
	else if (w_n_p[0] > count6(num, w_n_p) && w_n_p[0] > w_n_p[1]
			&& w_n_p[1] >= count6(num, w_n_p))
		i = count6(num, w_n_p) + d_wpc(save_f, w_n_p, num);
	else if (w_n_p[0] > count6(num, w_n_p) && w_n_p[0] > w_n_p[1] &&
			w_n_p[1] <= count6(num, w_n_p) && flag_check(save_f, '-'))
		i = count6(num, w_n_p)
			+ d_wcp_with_m(save_f, w_n_p, num);
	else
		i = count6(num, w_n_p) + d_wcp(save_f, w_n_p, num);
	return (i);
}
