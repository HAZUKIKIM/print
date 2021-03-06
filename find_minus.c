/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_minus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 19:35:52 by hmiyake           #+#    #+#             */
/*   Updated: 2018/07/26 00:42:14 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int find_minus(char *save_f)
{
    int i;

    i = 0;
    while (save_f[i] != '\0')
    {
        if (save_f[i] == '-')
            return (1);
        i++;
    }
    return (0);
}