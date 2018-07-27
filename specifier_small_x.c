/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_small_x.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 17:50:09 by hmiyake           #+#    #+#             */
/*   Updated: 2018/07/26 16:39:40 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t length_x(char *save_l, va_list ap)
{
    uintmax_t num;

    if (*save_l == 'h' && *(save_l + 1) == 'h')
        num = (unsigned char)va_arg(ap, uintmax_t);
    else if (*save_l == 'h')
        num = (unsigned short)va_arg(ap, uintmax_t);
    else if (*save_l == 'l' && *(save_l + 1) == 'l')
        num = (unsigned long long)va_arg(ap, uintmax_t);
    else if (*save_l == 'l')
        num = (unsigned long)va_arg(ap, uintmax_t);
    else if (*save_l == 'j')
        num = va_arg(ap, uintmax_t);
    else if (*save_l == 'z')
        num = (size_t)va_arg(ap, uintmax_t);
    else
        num = (unsigned int)va_arg(ap, uintmax_t);
    return (num);
}

int x_put_flag(char *save_f, int i, uintmax_t num)
{
    if (flag_check(save_f, '#') && num != 0)
    {
        ft_putchar('0');
        ft_putchar('x');
        i = i + 2;
    }
    return (i);
}

int x_c_is_biggest(char *save_f, int *w_n_p, uintmax_t num)
{
    int i;
    
    i = 0;
    i = x_put_flag(save_f, i, num);
    if (num == 0 && w_n_p[1] == 0)
        return(i);
    else
    {
        x_ft_putnumber(num);
        return (i);
    }
}

int x_p_is_biggest(char *save_f, int *w_n_p, uintmax_t num)
{
    int i;
    int j;
    
    i = 0;
    i = x_put_flag(save_f, i, num);
    j = i;
    while(i < (w_n_p[1] - count4(num, w_n_p) + j))
    {
        ft_putnumber(0);
        i++;
    }
    x_ft_putnumber(num);
    return (i);
}

int specifier_small_x(va_list ap, char *save_f, int *w_n_p, char *save_l)
{
    uintmax_t num;
    int i;

    num = length_x(save_l, ap);
    if (count4(num, w_n_p) >= w_n_p[0] && count4(num, w_n_p) >= w_n_p[1])
        i = count4(num, w_n_p) + x_c_is_biggest(save_f, w_n_p, num);
    else if (w_n_p[1] > count4(num, w_n_p) && w_n_p[1] >= w_n_p[0]) 
        i = count4(num, w_n_p) + x_p_is_biggest(save_f, w_n_p, num);
    else if (w_n_p[0] > count4(num, w_n_p) && w_n_p[0] > w_n_p[1] && w_n_p[1] > count4(num, w_n_p) && flag_check(save_f, '-'))
        i = count4(num, w_n_p) + x_w_is_biggest_p_is_second_with_m(save_f, w_n_p, num);
    else if (w_n_p[0] > count4(num, w_n_p) && w_n_p[0] > w_n_p[1] && w_n_p[1] > count4(num, w_n_p))
        i = count4(num, w_n_p) + x_w_is_biggest_p_is_second(save_f, w_n_p, num);
    else if (w_n_p[0] > count4(num, w_n_p) && w_n_p[0] > w_n_p[1] && w_n_p[1] < count4(num, w_n_p) && flag_check(save_f, '-'))
        i = count4(num, w_n_p) + x_w_is_biggest_c_is_second_with_m(save_f, w_n_p, num);
    else
        i = count4(num, w_n_p) + x_w_is_biggest_c_is_second(save_f, w_n_p, num);
    return (i);
}
