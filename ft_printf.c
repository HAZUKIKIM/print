/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 22:17:58 by hmiyake           #+#    #+#             */
/*   Updated: 2018/07/26 17:28:42 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char* str, ...)
{
    int i;
    char *save_f;
    int w_n_p[2];
    char *save_l;
    va_list ap;
    int count;

    i = 0;
    count = 0;
    va_start(ap, str);
    save_f = NULL;
    save_l = NULL;
    while(str[i] != '\0')
    {
        if (str[i] != '%')
        {
            ft_putchar(str[i]);
            count++;
        }
        if (str[i] == '%')
        {
            i++;
            save_f = flag(str, save_f, i);
            i = skip_flag(str, i);
            w_n_p[0] = width(str, i, ap);
            i = skip_width(str, i);
            w_n_p[1] = precision(str, i, ap);
            i = skip_precision(str, i);
            save_l = length(str, save_l, i);
            i = skip_length(str, i);
            if (str[i] == 'c')
                count += specifier_small_c(ap, save_f, w_n_p, save_l);
            else if (str[i] == 'C')
                count += specifier_capital_c(ap, save_f, w_n_p, save_l);
            else if (str[i] == 's')
                count += specifier_small_s(ap, save_f, w_n_p, save_l);
            else if (str[i] == 'S')
                count += specifier_capital_s(ap, save_f, w_n_p, save_l);
            else if (str[i] == 'd')
                count += specifier_small_d(ap, save_f, w_n_p, save_l);
            else if (str[i] == 'D')
                count += specifier_capital_d(ap, save_f, w_n_p, save_l);
            else if (str[i] == 'x')
                count += specifier_small_x(ap, save_f, w_n_p, save_l);
            else if (str[i] == 'X')
                count += specifier_capital_x(ap, save_f, w_n_p, save_l);
            else if (str[i] == 'o')
                count += specifier_small_o(ap, save_f, w_n_p, save_l);
            else if (str[i] == 'O')
                count += specifier_capital_o(ap, save_f, w_n_p, save_l);
            else if (str[i] == 'u')
                count += specifier_small_u(ap, save_f, w_n_p, save_l);
            else if (str[i] == 'U')
                count += specifier_capital_u(ap, save_f, w_n_p, save_l);
            else if (str[i] == 'i')
                count += specifier_small_d(ap, save_f, w_n_p, save_l);
            else if (str[i] == 'p')
                count += specifier_small_p(ap, save_f, w_n_p, save_l);
            else if (str[i] == '%')
                count += specifier_percentage(save_f, w_n_p);
        }
        i++;
    }
    if(save_l)
        free(save_l);
    if(save_f)
        free(save_f);
    va_end(ap);
    return(count);
}

// int main(void)
// {   
//     // uintmax_t a;
//     // uintmax_t b;

//     ft_printf("%lu", -42);
//     printf("\n");
//     printf("%lu", -42);
//     printf("\n");
//     // printf("%d\n%d\n", a, b);

//     return (0);
// }