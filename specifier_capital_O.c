/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_capital_O.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 11:52:38 by hmiyake           #+#    #+#             */
/*   Updated: 2018/07/26 17:10:00 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int specifier_capital_o(va_list ap, char *save_f, int *w_n_p, char *save_l)
{
    uintmax_t num;
    int i;

    num = (long)va_arg(ap, uintmax_t);
    if (count5(num, w_n_p) >= w_n_p[0] && count5(num, w_n_p) >= w_n_p[1])
        i = count5(num, w_n_p) + o_c_is_biggest(save_f, w_n_p, num);
    else if (w_n_p[1] > count5(num, w_n_p) && w_n_p[1] >= w_n_p[0]) 
        i = count5(num, w_n_p) + o_p_is_biggest(save_f, w_n_p, num);
    else if (w_n_p[0] > count5(num, w_n_p) && w_n_p[0] > w_n_p[1] && w_n_p[1] >= count5(num, w_n_p) && flag_check(save_f, '-'))
        i = count5(num, w_n_p) + o_w_is_biggest_p_is_second_with_m(save_f, w_n_p, num);
    else if (w_n_p[0] > count5(num, w_n_p) && w_n_p[0] > w_n_p[1] && w_n_p[1] >= count5(num, w_n_p))
        i = count5(num, w_n_p) + o_w_is_biggest_p_is_second(save_f, w_n_p, num);
    else if (w_n_p[0] > count5(num, w_n_p) && w_n_p[0] > w_n_p[1] && w_n_p[1] <= count5(num, w_n_p) && flag_check(save_f, '-'))
        i = count5(num, w_n_p) + o_w_is_biggest_c_is_second_with_m(save_f, w_n_p, num);
    else
        i = count5(num, w_n_p) + o_w_is_biggest_c_is_second(save_f, w_n_p, num);
    return (i);
}