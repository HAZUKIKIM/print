/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_capital_s.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 14:22:45 by hmiyake           #+#    #+#             */
/*   Updated: 2018/07/26 18:57:09 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int specifier_capital_s(va_list ap, char *save_f, int *w_n_p)
{
    wchar_t *w;
    int i;

    w = NULL;
    if (find_minus(save_f))
        i = minus_n_l_2(ap, w, w_n_p);
    else
        i = no_minus_n_l_2(ap, w, w_n_p);
    return (i);
}