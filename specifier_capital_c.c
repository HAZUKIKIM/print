/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_capital_c.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 19:39:54 by hmiyake           #+#    #+#             */
/*   Updated: 2018/07/25 18:24:49 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int specifier_capital_c(va_list ap, char *save_f, int *w_n_p, char *save_l)
{
    wint_t w;
    unsigned char c;
    int i;

    i = 0;
    if (find_minus(save_f))
        i = minus_n_l(ap, w, w_n_p, i);
    else
        i = no_minus_n_l(ap, w, w_n_p, i);
    return (i);
}