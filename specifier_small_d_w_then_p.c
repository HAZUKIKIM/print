/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_small_d_w_then_p.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 17:25:07 by hmiyake           #+#    #+#             */
/*   Updated: 2018/07/26 17:50:49 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int w_is_biggest_p_is_second_positive(char *save_f, int *w_n_p, intmax_t num, int i)
{
    if (flag_check(save_f, '+'))
    {
        while (i < (w_n_p[0] - w_n_p[1] - 1))
            i = put_space(i);
        ft_putchar('+');
        i++;
    }
    else
    {
        while(i < (w_n_p[0] - w_n_p[1]))
            i = put_space(i);
    }
    return (i);
}

int w_is_biggest_p_is_second(char *save_f, int *w_n_p, intmax_t num)
{
    int i;
    int j;
    
    i = 0;
    if (num >= 0)
        i = w_is_biggest_p_is_second_positive(save_f, w_n_p, num, i);
    else
    {
        while (i < (w_n_p[0] - w_n_p[1] - 1))
            i = put_space(i);
        ft_putchar('-');
        i++;
        num = num * -1;
    }
    j = i;
    while (i < (w_n_p[1] - count6(num, w_n_p) + j))
        i = put_zero(i);
    ft_putnumber(num);
    return (i);
}

int w_is_biggest_p_is_second_with_m_positive(char *save_f, int *w_n_p, intmax_t num)
{
    int i;
    int j;
    
    i = 0;
    if (flag_check(save_f, '+') || flag_check(save_f, ' '))
    {
        i = put_flag(save_f, i);
        j = i;
        while(i < (w_n_p[1] - count6(num, w_n_p) + j))
            i = put_zero(i);
        ft_putnumber(num);
        j = i;
        while (i < (w_n_p[0] - w_n_p[1] - 1 + j))
            i = put_space(i);
    } 
    else
    {
        while(i < (w_n_p[1] - count6(num, w_n_p)))
            i = put_zero(i);
        ft_putnumber(num);
        j = i;
        while(i < (w_n_p[0] - w_n_p[1] + j))
            i = put_space(i);
    }
    return (i);
}

int w_is_biggest_p_is_second_with_m_negative(char *save_f, int *w_n_p, intmax_t num)
{
    int i;
    int j;
    
    i = 0;
    ft_putchar('-');
    i++;
    j = i;
    while (i < (w_n_p[1] - count6(num, w_n_p) + j))
        i = put_zero(i);
    num = num * -1;
    ft_putnumber(num);
    j = i;
    while (i < (w_n_p[0] - w_n_p[1] - 1 + j))
        i = put_space(i);
    return (i);
}

int w_is_biggest_p_is_second_with_m(char *save_f, int *w_n_p, intmax_t num)
{
    if (num >= 0)
        return (w_is_biggest_p_is_second_with_m_positive(save_f, w_n_p, num));
    else
        return (w_is_biggest_p_is_second_with_m_negative(save_f, w_n_p, num));
}