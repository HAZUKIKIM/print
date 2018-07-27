/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 15:49:24 by hmiyake           #+#    #+#             */
/*   Updated: 2018/07/26 17:53:48 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <stdint.h>

int ft_printf(const char* str, ...);

void put_and_free(void *a);

void ft_putchar(char c);
wchar_t *put_st(wchar_t *w);
char *put_str(char *str);
void	ft_putnumber(intmax_t n);
void	x_ft_putnumber(uintmax_t n);
void	capital_x_ft_putnumber(uintmax_t n);
void	small_o_ft_putnumber(uintmax_t n);

void initialize_save_f(char *save_f);
int checksave(char *save, char c);
char *flag(const char *str, char *save_f, int i);
int skip_flag(const char *str, int i);

int width(const char *str, int i, va_list ap);
int skip_width(const char *str, int i);

int precision(const char * str, int i, va_list ap);
int skip_precision(const char *str, int i);

void initialize_save_l(char *save_l);
char *length(const char *str, char *save_l, int i);
int skip_length(const char *str, int i);

int find_minus(char *save_f);

int minus_n_l(va_list ap, wint_t w, int *w_n_p, int i);
int minus_n_no_l(va_list ap, unsigned char c, int *w_n_p, int i);
int no_minus_n_l(va_list ap, wint_t w, int *w_n_p, int i);
int no_minus_n_no_l(va_list ap, unsigned char c, int *w_n_p, int i);
int specifier_small_c(va_list ap, char *save_f, int *w_n_p, char *save_l);

int specifier_capital_c(va_list ap, char *save_f, int *w_n_p, char *save_l);

int count1(wchar_t *w);
int count2(char *s);
int count3(uintmax_t num, int *w_n_p);
int count4(uintmax_t num, int *w_n_p);
int count5(uintmax_t num, int *w_n_p);
int count6(intmax_t num, int *w_n_p);

int nothing(char *s, int count);
int go_to_the_end_of_width(int i, int *w_n_p);
int increase_together(char *a, char *s, int i);
char *malloc_a_and_put_null(char *a, int *w_n_p);
int no_m_no_l_w_is_biggest(char *a, int *w_n_p, int count, char *s);
int no_m_no_l_p_is_biggest(char *a, int *w_n_p, int count, char *s);
int no_m_no_l_c_is_biggest(char *a, int *w_n_p, int count, char *s);
int m_no_l_w_is_biggest(char *a, int *w_n_p, int count, char *s);
int m_no_l_p_is_biggest(char *a, int *w_n_p, int count, char *s);
int m_no_l_c_is_biggest(char *a, int *w_n_p, int count, char *s);
int no_minus_n_no_l_2(va_list ap, char *s, int *w_n_p);
int minus_n_no_l_2(va_list ap, char *s, int *w_n_p);

int minus_n_l_2(va_list ap, wchar_t *w, int *w_n_p);
int no_minus_n_l_2(va_list ap, wchar_t *w, int *w_n_p);
int specifier_small_s(va_list ap, char *save_f, int *w_n_p, char *save_l);

int nothing_l(wchar_t *w, int count);
int increase_together_l(wchar_t *a, wchar_t *w, int i);
int fill_with_space(wchar_t *a, int i);
wchar_t *malloc_a_and_put_null_l(wchar_t *a, int *w_n_p);

int no_m_n_l_w_is_biggest(wchar_t *w, int *w_n_p, int count, wchar_t *a);
int no_m_n_l_p_is_biggest(wchar_t *w, int *w_n_p, int count, wchar_t *a);
int no_m_n_l_c_is_biggest(wchar_t *w, int *w_n_p, int count, wchar_t *a);

int m_n_l_w_is_biggest(wchar_t *w, int *w_n_p, int count, wchar_t *a);
int m_n_l_p_is_biggest(wchar_t *w, int *w_n_p, int count, wchar_t *a);
int m_n_l_c_is_biggest(wchar_t *w, int *w_n_p, int count, wchar_t *a);

int specifier_capital_s(va_list ap, char *save_f, int *w_n_p, char *save_l);

intmax_t length_d(char *save_l, va_list ap);
int flag_check(char *save_f, char flag);
int put_flag(char *save_f, int i);
int put_space(int i);
int put_zero(int i);

int p_is_biggest(char *save_f, int *w_n_p, intmax_t num);
int c_is_biggest(char *save_f, int *w_n_p, intmax_t num);
int specifier_small_d(va_list ap, char *save_f, int *w_n_p, char *save_l);

int w_is_biggest_p_is_second_positive(char *save_f, int *w_n_p, intmax_t num, int i);
int w_is_biggest_p_is_second(char *save_f, int *w_n_p, intmax_t num);
int w_is_biggest_p_is_second_with_m(char *save_f, int *w_n_p, intmax_t num);
int w_is_biggest_p_is_second_with_m_positive(char *save_f, int *w_n_p, intmax_t num);
int w_is_biggest_p_is_second_with_m_negative(char *save_f, int *w_n_p, intmax_t num);

int w_is_biggest_c_is_second_positive(char *save_f, int *w_n_p, intmax_t num, int i);
int w_is_biggest_c_is_second(char *save_f, int *w_n_p, intmax_t num);
int w_is_biggest_c_is_second_with_m(char *save_f, int *w_n_p, intmax_t num);
int w_is_biggest_c_is_second_with_m_positive(char *save_f, int *w_n_p, intmax_t num);
int w_is_biggest_c_is_second_with_m_negative(char *save_f, int *w_n_p, intmax_t num);

int specifier_capital_d(va_list ap, char *save_f, int *w_n_p, char *save_l);

uintmax_t length_x(char *save_l, va_list ap);
int x_put_flag(char *save_f, int i, uintmax_t num);
int x_c_is_biggest(char *save_f, int *w_n_p, uintmax_t num);
int x_p_is_biggest(char *save_f, int *w_n_p, uintmax_t num);
int specifier_small_x(va_list ap, char *save_f, int *w_n_p, char *save_l);

int x_w_is_biggest_p_is_second(char *save_f, int *w_n_p, uintmax_t num);
int x_w_is_biggest_p_is_second_with_m(char *save_f, int *w_n_p, uintmax_t num);
int x_w_is_biggest_c_is_second(char *save_f, int *w_n_p, uintmax_t num);
int x_w_is_biggest_c_is_second_with_m(char *save_f, int *w_n_p, uintmax_t num);

int capital_x_put_flag(char *save_f, int i);
int capital_x_c_is_biggest(char *save_f, int *w_n_p, uintmax_t num);
int capital_x_p_is_biggest(char *save_f, int *w_n_p, uintmax_t num);
int specifier_capital_x(va_list ap, char *save_f, int *w_n_p, char *save_l);

int capital_x_w_is_biggest_p_is_second(char *save_f, int *w_n_p, uintmax_t num);
int capital_x_w_is_biggest_p_is_second_with_m(char *save_f, int *w_n_p, uintmax_t num);
int capital_x_w_is_biggest_c_is_second(char *save_f, int *w_n_p, uintmax_t num);
int capital_x_w_is_biggest_c_is_second_with_m(char *save_f, int *w_n_p, uintmax_t num);

int o_put_flag(char *save_f, int i);
int o_c_is_biggest(char *save_f, int *w_n_p, uintmax_t num);
int o_p_is_biggest(char *save_f, int *w_n_p, uintmax_t num);
int specifier_small_o(va_list ap, char *save_f, int *w_n_p, char *save_l);

int o_w_is_biggest_p_is_second(char *save_f, int *w_n_p, uintmax_t num);
int o_w_is_biggest_p_is_second_with_m(char *save_f, int *w_n_p, uintmax_t num);
int o_w_is_biggest_c_is_second(char *save_f, int *w_n_p, uintmax_t num);
int o_w_is_biggest_c_is_second_with_m(char *save_f, int *w_n_p, uintmax_t num);

int specifier_capital_o(va_list ap, char *save_f, int *w_n_p, char *save_l);

int u_c_is_biggest(char *save_f, int *w_n_p, uintmax_t num);
int u_p_is_biggest(char *save_f, int *w_n_p, uintmax_t num);
int u_w_is_biggest_p_is_second(char *save_f, int *w_n_p, uintmax_t num);
int u_w_is_biggest_c_is_second(char *save_f, int *w_n_p, uintmax_t num);
int specifier_small_u(va_list ap, char *save_f, int *w_n_p, char *save_l);

int specifier_capital_u(va_list ap, char *save_f, int *w_n_p, char *save_l);

void p_put_flag(char *save_f);
void p_c_is_bigger(char *save_f, int *w_n_p, uintmax_t num);
void p_w_is_bigger(char *save_f, int *w_n_p, uintmax_t num);
int specifier_small_p(va_list ap, char *save_f, int *w_n_p, char *save_l);

int specifier_percentage_with_flag(char *save_f, int *w_n_p);
int specifier_percentage(char *save_f, int *w_n_p);

#endif