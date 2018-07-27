/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_small_d.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 12:21:20 by hmiyake           #+#    #+#             */
/*   Updated: 2018/07/26 17:51:04 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int put_zero(int i)
{
    ft_putnumber(0);
    i++;
    return (i);  
}

int c_is_biggest(char *save_f, int *w_n_p, intmax_t num)
{
    int i;
    
    i = 0;
    if (num >= 0)
        i = put_flag(save_f, i);
    else
        i++;
    if (num == 0 && w_n_p[1] == 0)
        return(i);
    else
    {
        ft_putnumber(num);
        return (i);
    }
}

int p_is_biggest(char *save_f, int *w_n_p, intmax_t num)
{
    int i;
    int j;
    
    i = 0;
    if (num >= 0)
    {
        i = put_flag(save_f, i);
        j = i;
        while(i < (w_n_p[1] - count6(num, w_n_p) + j))
        {
            ft_putnumber(0);
            i++;
        }
    }
    else if (num < 0)
    {
        ft_putchar('-');
        i++;
        while (i < (w_n_p[1] - count6(num, w_n_p) + 1))
        {
            ft_putnumber(0);
            i++;
        }
        num = num * -1;
    }
    ft_putnumber(num);
    return (i);
}

int    w_is_biggest_c_is_second_with_m(char *save_f, int *w_n_p, intmax_t num)
{
    if (num >= 0)
        return (w_is_biggest_c_is_second_with_m_positive(save_f, w_n_p, num));
    else
        return (w_is_biggest_c_is_second_with_m_negative(save_f, w_n_p, num));
}

int specifier_small_d(va_list ap, char *save_f, int *w_n_p, char *save_l)
{
    intmax_t num;
    int i;

    num = length_d(save_l, ap);
    if (count6(num, w_n_p) >= w_n_p[0] && count6(num, w_n_p) >= w_n_p[1])
        i = count6(num, w_n_p) + c_is_biggest(save_f, w_n_p, num);
    else if (w_n_p[1] > count6(num, w_n_p) && w_n_p[1] >= w_n_p[0])
        i = count6(num, w_n_p) + p_is_biggest(save_f, w_n_p, num);
    else if (w_n_p[0] > count6(num, w_n_p) && w_n_p[0] > w_n_p[1] && w_n_p[1] > count6(num, w_n_p) && flag_check(save_f, '-'))
        i = count6(num, w_n_p) + w_is_biggest_p_is_second_with_m(save_f, w_n_p, num);
    else if (w_n_p[0] > count6(num, w_n_p) && w_n_p[0] > w_n_p[1] && w_n_p[1] > count6(num, w_n_p))
        i = count6(num, w_n_p) + w_is_biggest_p_is_second(save_f, w_n_p, num);
    else if (w_n_p[0] > count6(num, w_n_p) && w_n_p[0] > w_n_p[1] && w_n_p[1] < count6(num, w_n_p) && flag_check(save_f, '-'))
        i = count6(num, w_n_p) + w_is_biggest_c_is_second_with_m(save_f, w_n_p, num);
    else
        i = count6(num, w_n_p) + w_is_biggest_c_is_second(save_f, w_n_p, num);
    return (i);
}