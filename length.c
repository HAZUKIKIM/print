/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 15:56:53 by hmiyake           #+#    #+#             */
/*   Updated: 2018/07/18 15:57:48 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void initialize_save_l(char *save_l)
{
    int i;

    i = 0;
    while (i < 2)
    {
        save_l[i] = 0;
        i++;
    }
}

char *length(const char *str, char *save_l, int i)
{
    int h;

    h = 0;
    save_l = (char *)malloc(sizeof(char) * 2);
    initialize_save_l(save_l);
    while(str[i] == 'h' || str[i] == 'l' || str[i] == 'j' || str[i] == 'z')
    {
        save_l[h] = str[i];
        h++;
        i++;
    }
    return (save_l);
}

int skip_length(const char *str, int i)
{
    while (str[i] == 'h' || str[i] == 'l' || str[i] == 'j' || str[i] == 'z')
        i++;
    return (i);
}