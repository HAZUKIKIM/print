/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_capital_D.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 17:40:22 by hmiyake           #+#    #+#             */
/*   Updated: 2018/07/26 17:50:30 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int specifier_capital_d(va_list ap, char *save_f, int *w_n_p, char *save_l)
{
    intmax_t num;
    int i;

    num = (long)va_arg(ap, intmax_t);
    if (count6(num, w_n_p) >= w_n_p[0] && count6(num, w_n_p) >= w_n_p[1])
        i = count6(num, w_n_p) + c_is_biggest(save_f, w_n_p, num);
    else if (w_n_p[1] > count6(num, w_n_p) && w_n_p[1] >= w_n_p[0]) 
        i = count6(num, w_n_p) + p_is_biggest(save_f, w_n_p, num);
    else if (w_n_p[0] > count6(num, w_n_p) && w_n_p[0] > w_n_p[1] && w_n_p[1] >= count6(num, w_n_p) && flag_check(save_f, '-'))
        i = count6(num, w_n_p) + w_is_biggest_p_is_second_with_m(save_f, w_n_p, num);
    else if (w_n_p[0] > count6(num, w_n_p) && w_n_p[0] > w_n_p[1] && w_n_p[1] >= count6(num, w_n_p))
        i = count6(num, w_n_p) + w_is_biggest_p_is_second(save_f, w_n_p, num);
    else if (w_n_p[0] > count6(num, w_n_p) && w_n_p[0] > w_n_p[1] && w_n_p[1] <= count6(num, w_n_p) && flag_check(save_f, '-'))
        i = count6(num, w_n_p) + w_is_biggest_c_is_second_with_m(save_f, w_n_p, num);
    else
        i = count6(num, w_n_p) + w_is_biggest_c_is_second(save_f, w_n_p, num);
    return (i);
}