/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_capital_U.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 12:41:01 by hmiyake           #+#    #+#             */
/*   Updated: 2018/07/26 17:09:19 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int specifier_capital_u(va_list ap, char *save_f, int *w_n_p, char *save_l)
{
    uintmax_t num;
    int i;

    num = (unsigned long)va_arg(ap, intmax_t);
    if (count3(num, w_n_p) >= w_n_p[0] && count3(num, w_n_p) >= w_n_p[1])
        i = count3(num, w_n_p) + u_c_is_biggest(save_f, w_n_p, num);
    else if (w_n_p[1] > count3(num, w_n_p) && w_n_p[1] >= w_n_p[0]) 
        i = count3(num, w_n_p) + u_p_is_biggest(save_f, w_n_p, num);
    else if (w_n_p[0] > count3(num, w_n_p) && w_n_p[0] > w_n_p[1] && w_n_p[1] >= count3(num, w_n_p))
        i = count3(num, w_n_p) + u_w_is_biggest_p_is_second(save_f, w_n_p, num);
    else
        i = count3(num, w_n_p) + u_w_is_biggest_c_is_second(save_f, w_n_p, num);
    return (i);
}