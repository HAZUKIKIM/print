/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_small_d_w_then_c.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 17:26:32 by hmiyake           #+#    #+#             */
/*   Updated: 2018/07/26 17:07:55 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int w_is_biggest_c_is_second_positive_with_flag(char *save_f, int *w_n_p, intmax_t num, int i)
{
   if (flag_check(save_f, '0') && w_n_p[1] == -1)
    {
        i = put_flag(save_f, i);
        while (i < (w_n_p[0] - count3(num, w_n_p)))
            i = put_zero(i);
    }
    else
    {
        while (i < (w_n_p[0] - count3(num, w_n_p) - 1))
            i = put_space(i);
        put_flag(save_f, i);
    }
    return (i);
}

int w_is_biggest_c_is_second_positive(char *save_f, int *w_n_p, intmax_t num, int i)
{
    if (flag_check(save_f, '+') || flag_check(save_f, ' '))
        i = w_is_biggest_c_is_second_positive_with_flag(save_f, w_n_p, num, i);   
    else
    {
        if (flag_check(save_f, '0') && w_n_p[1] == -1)
        {
            while (i < (w_n_p[0] - count3(num, w_n_p)))
                i = put_zero(i);
        }
        else
        {
            while (i < (w_n_p[0] - count3(num, w_n_p)))
                i = put_space(i);
        }
    }
    return (i);
}

int w_is_biggest_c_is_second(char *save_f, int *w_n_p, intmax_t num)
{
    int i;
    
    i = 0;
    if (num >= 0)
        i = w_is_biggest_c_is_second_positive(save_f, w_n_p, num, i);
    else if (num < 0)
    {  
        if (flag_check(save_f, '0') && w_n_p[1] == -1)
        {
            ft_putchar('-');
            i++;
            while (i < (w_n_p[0] - count3(num, w_n_p)))
                i = put_zero(i);
        }
        else
        {
            while (i < (w_n_p[0] - count3(num, w_n_p) - 1))
                i = put_space(i);
            ft_putchar('-');
            i++;
        }
        num = num * -1;
    }
    if (num == 0 && w_n_p[1] == 0)
        return(i);
    else
    {
        ft_putnumber(num);
        return (i);
    }   
}

int w_is_biggest_c_is_second_with_m_positive(char *save_f, int *w_n_p, intmax_t num)
{
    int i;
    int j;
    
    i = 0;
    if (flag_check(save_f, '+') || flag_check(save_f, ' '))
    {
        i = put_flag(save_f, i);
        ft_putnumber(num);
        j = i;
        while (i < (w_n_p[0] - count3(num, w_n_p) - 1 + j))
            i = put_space(i);
    } 
    else
    {
        ft_putnumber(num);
        while(i < (w_n_p[0] - count3(num, w_n_p)))
            i = put_space(i);
    }
    return (i);
}

int w_is_biggest_c_is_second_with_m_negative(char *save_f, int *w_n_p, intmax_t num)
{
    int i;
    int j;
    
    i = 0;
    ft_putchar('-');
    i++;
    num = num * -1;
    ft_putnumber(num);
    j = i;
    while (i < (w_n_p[0] - count3(num, w_n_p) - 1 + j))
        i = put_space(i);
    return (i);
}