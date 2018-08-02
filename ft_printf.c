/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 22:17:58 by hmiyake           #+#    #+#             */
/*   Updated: 2018/08/01 22:09:59 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	c_to_x(va_list ap, char *save_f, int *w_n_p, char *save_l, int count, const char *str, int i)
{
	if (str[i] == 'c')
		count += specifier_small_c(ap, save_f, w_n_p, save_l);
	else if (str[i] == 'C')
		count += specifier_capital_c(ap, save_f, w_n_p);
	else if (str[i] == 's')
		count += specifier_small_s(ap, save_f, w_n_p, save_l);
	else if (str[i] == 'S')
		count += specifier_capital_s(ap, save_f, w_n_p);
	else if (str[i] == 'd')
		count += specifier_small_d(ap, save_f, w_n_p, save_l);
	else if (str[i] == 'D')
		count += specifier_capital_d(ap, save_f, w_n_p);
	else if (str[i] == 'x')
		count += specifier_small_x(ap, save_f, w_n_p, save_l);
	else if (str[i] == 'X')
		count += specifier_capital_x(ap, save_f, w_n_p, save_l);
	return (count);
}

int	o_to_percentage(va_list ap, char *save_f, int *w_n_p, char *save_l, int count, const char *str, int i)
{
	if (str[i] == 'o')
		count += specifier_small_o(ap, save_f, w_n_p, save_l);
	else if (str[i] == 'O')
		count += specifier_capital_o(ap, save_f, w_n_p);
	else if (str[i] == 'u')
		count += specifier_small_u(ap, save_f, w_n_p, save_l);
	else if (str[i] == 'U')
		count += specifier_capital_u(ap, save_f, w_n_p);
	else if (str[i] == 'i')
		count += specifier_small_d(ap, save_f, w_n_p, save_l);
	else if (str[i] == 'p')
		count += specifier_small_p(ap, save_f, w_n_p);
	else if (str[i] == '%')
		count += specifier_percentage(save_f, w_n_p);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	char	*save_f;
	int		w_n_p[2];
	char	*save_l;
	va_list	ap;
	int		count;

	i = 0;
	count = 0;
	va_start(ap, str);
	save_f = NULL;
	save_l = NULL;
	while (str[i] != '\0')
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
			if (str[i] == 'c' || str[i] == 'C' || str[i] == 's' || str[i] == 'S'
			|| str[i] == 'd' || str[i] == 'D' || str[i] == 'x' || str[i] == 'X')
				count = c_to_x(ap, save_f, w_n_p, save_l, count, str, i);
			else
				count = o_to_percentage(ap, save_f, w_n_p, save_l, count, str, i);
			free(save_l);
			free(save_f);
		}
		i++;
	}
	va_end(ap);
	return (count);
}

// int	main(void)
// {
//   ft_printf("\n");
//   ft_printf("%%\n");
//   ft_printf("%d\n", 42);
//   ft_printf("%d%d\n", 42, 41);
//   ft_printf("%d%d%d\n", 42, 43, 44);
//   ft_printf("%ld\n", 2147483647);
//   ft_printf("%lld\n", 9223372036854775807);
//   ft_printf("%x\n", 505);
//   ft_printf("%X\n", 505);
//   ft_printf("%p\n", &ft_printf);
//   ft_printf("%20.15d\n", 54321);
//   ft_printf("%-10d\n", 3);
//   ft_printf("% d\n", 3);
//   ft_printf("%+d\n", 3);
//   ft_printf("%010d\n", 1);
//   ft_printf("%hhd\n", 0);
//   ft_printf("%jd\n", 9223372036854775807);
//   ft_printf("%zd\n", 4294967295);
//   ft_printf("%\n");
//   ft_printf("%U\n", 4294967295);
//   ft_printf("%u\n", 4294967295);
//   ft_printf("%o\n", 40);
//   ft_printf("%%#08x\n", 42);
//   ft_printf("%x\n", 1000);
//   ft_printf("%#X\n", 1000);
//   ft_printf("%s\n", NULL);
//   ft_printf("%S\n", L"ݗݜशব");
//   ft_printf("%s%s\n", "test", "test");
//   ft_printf("%s%s%s\n", "test", "test", "test");
//   ft_printf("%C\n", 15000);
//   while (1);
//   return (0);
// }