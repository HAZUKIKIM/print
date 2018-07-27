/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 16:24:41 by hmiyake           #+#    #+#             */
/*   Updated: 2018/07/26 17:00:38 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int count1(wchar_t *w)
{
    int i;

    i = 0;
    while (w[i] != '\0')
        i++;
    return (i);
}

int count2(char *s)
{
    int i;

    i = 0;
    if (s)
    {
        while (s[i] != '\0')
            i++;
        return (i);
    }
    else
        return (6);
}

int count3(intmax_t num, int *w_n_p)
{
    int count;
    
    count = 0;
    if (num == 0 && w_n_p[1] != 0)
        return (1);
    else if (num == 0)
        return(0);
    while (num != 0)
    {
        num = num / 10;
        count++;
    }
    return (count);
}

int count4(uintmax_t num, int *w_n_p)
{
    int count;
    
    count = 0;
    if (num == 0 && w_n_p[1] != 0)
        return (1);
    else if (num == 0)
        return(0);    
    while (num != 0)
    {
        num = num / 16;
        count++;
    }
    return (count);
}

int count5(uintmax_t num, int *w_n_p)
{
    int count;
    
    count = 0;
    if (num == 0 && w_n_p[1] != 0)
        return (1);
    else if (num == 0)
        return(0);
    while (num != 0)
    {
        num = num / 8;
        count++;
    }
    return (count);
}