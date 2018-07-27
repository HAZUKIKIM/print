/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_small_d_related.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 17:27:50 by hmiyake           #+#    #+#             */
/*   Updated: 2018/07/26 13:54:33 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t length_d(char *save_l, va_list ap)
{
    intmax_t num;

    if (*save_l == 'h' && *(save_l + 1) == 'h')
        num = (signed char)va_arg(ap, intmax_t);
    else if (*save_l == 'h')
        num = (short)va_arg(ap, intmax_t);
    else if (*save_l == 'l' && *(save_l + 1) == 'l')
        num = (long long)va_arg(ap, intmax_t);
    else if (*save_l == 'l')
        num = (long)va_arg(ap, intmax_t);
    else if (*save_l == 'j')
        num = va_arg(ap, intmax_t);
    else if (*save_l == 'z')
        num = (size_t)va_arg(ap, intmax_t);
    else
        num = (int)va_arg(ap, intmax_t);
    return (num);
}

int flag_check(char *save_f, char flag)
{
    int i;
    
    i = 0;
    while(i < 5)
    {
        if (save_f[i] == flag)
            return (1);
        i++;
    }
    return (0);
}

int put_flag(char *save_f, int i)
{
    if (flag_check(save_f, '+'))
    {
        ft_putchar('+');
        i++;
    }
    else if (flag_check(save_f, ' '))
    {
        ft_putchar(' ');
        i++;
    }
    return (i);
}

int put_space(int i)
{
    ft_putchar(' ');
    i++;
    return (i);  
}