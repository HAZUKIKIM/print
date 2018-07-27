/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 15:52:46 by hmiyake           #+#    #+#             */
/*   Updated: 2018/07/18 15:54:08 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void initialize_save_f(char *save_f)
{
    int i;

    i = 0;
    while (i < 5)
    {
        save_f[i] = 0;
        i++;
    }
}

int checksave(char *save, char c)
{
    int h;
    
    h = 0;
    while (h < 5)
    {
        if (save[h] == c)
            return(1);
        h++;
    }
    return (0);
}

char *flag(const char *str, char *save_f, int i)
{
    int h;
    
    h = 0;
    save_f = (char *)malloc(sizeof(char) * 5);
    initialize_save_f(save_f);
    while (str[i] == '#' || str[i] == '0' || str[i] == '+' || str[i] == '-' || str[i] == ' ')
    {
        if (!checksave(save_f, str[i]))
        {
            save_f[h] = str[i];
            h++;
        }
        i++;
    }
    return(save_f);
}

int skip_flag(const char *str, int i)
{
    while (str[i] == '#' || str[i] == '0' || str[i] == '+' || str[i] == '-' || str[i] == ' ')
        i++;
    return (i);
}