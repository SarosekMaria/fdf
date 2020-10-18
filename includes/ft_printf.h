/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:22:19 by sassassi          #+#    #+#             */
/*   Updated: 2020/03/12 11:57:36 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# define MAX_LONG_LONG	9223372036854775807

typedef struct		s_struct
{
	const char		*format;

	va_list			ap;
	int				i;
	int				len;
	int				lenp;
	int				fd;
	int				minus;
	int				plus;
	int				space;
	int				zero;
	int				hash;
	int				width;
	int				precision;
	int				precisionft;
	int				precisionp;
	int				length;
	int				sign;
	int				asterisk;
	char			conversion;
}					t_struct;

struct				s_2powers
{
	int				pow;
	int				len;
	char			num[10000];
};

int					ft_printf(const char *format, ...);
t_struct			*initialize(t_struct *list);
void				ft_reset_struct(t_struct *list);
int					ft_formatparse(const char *format, t_struct *list);
void				ft_parse_flags(const char *format, t_struct *list);
void				ft_parse_width(const char *format, t_struct *list);
void				ft_parse_precision(const char *format, t_struct *list);
void				ft_parse_length(const char *format, t_struct *list);
void				ft_print(const char *format, t_struct *list);
int					ft_unbrlen(uintmax_t value, int base);
int					ft_nbr_len(intmax_t value, int base);
int					ft_uitoa_base(uintmax_t value, int base, char x);
void				ft_print_percent(const char *format, t_struct *list);
void				ft_print_char(const char *format, t_struct *list);
void				ft_print_c_char(unsigned char c, t_struct *list);
void				ft_print_w_char(wchar_t wc, t_struct *list);
void				ft_writewchar(wchar_t wc, t_struct *list);
void				ft_print_string(const char *format, t_struct *list);
void				ft_string(char *str, t_struct *list);
void				ft_wstring(wchar_t *wstr, t_struct *list);
void				ft_putwstr(wchar_t *wstr, t_struct *list, int max);
int					ft_wstrlen(wchar_t *wstr, t_struct *list);
void				ft_print_decimal(char conversion, t_struct *m);
int					ft_print_decimal_nbr(intmax_t nbr, t_struct *list);
void				ft_print_decimal_right(intmax_t nbr, t_struct *list);
void				ft_print_decimal_right2(int nbrlen, t_struct *list,
		intmax_t nbr);
void				ft_print_decimal_left(intmax_t nbr, t_struct *list);
void				ft_print_float(char conversion, t_struct *m);
void				ft_print_octal(char conversion, t_struct *m);
void				ft_itoa_base(unsigned long long int nb, int base,
		t_struct *m, char *buf);
void				ft_bitwise_shift(char *s, int *i, int *id);
void				ft_bitwise_shift_buf(char *s, int len_buf, char c);
void				ft_print_hex(char conversion, t_struct *m);
void				ft_buf_init_dioux(char *buf, t_struct *m);
void				ft_buf_init_o(char *buf, t_struct *m, int len_buf);
void				ft_buf_init_u(char *buf, t_struct *m, int len_buf);
void				ft_buf_init_d(char *buf, t_struct *m, int len_buf);
void				ft_buf_init_x(char *buf, t_struct *m, int len_buf);
void				ft_print_udecimal(char conversion, t_struct *m);
void				ft_buf_init_float(char *int_part, char *frac_part,
		t_struct *m);
char				*ft_itoa_u(unsigned long long int n);
char				*ft_itoa_s(long long int n);
void				ft_print_pointer(const char *format, t_struct *list);
void				ft_if_hash(t_struct *m, char *buf, int *len_buf);
char				*ft_sum_str_int(char *dst, char *src);
void				ft_buf_init_inff(char *int_part, t_struct *m);
void				ft_print_binar(const char *format, t_struct *list);
void				ft_print_binar2(uintmax_t nbr, t_struct *list);
void				ft_overflow_digit_check(char *dst, int id);
char				*ft_sum_str_frac(char *dst, char *src, char *int_part,
		int is);
char				*ft_pow_str_10(int degree, char *tmp);
char				*ft_pow_str_2(int degree, char *tmp, int *d);
unsigned long long	ft_pow(int base, int degree);
char				*ft_division_str(int degree, char *tmp, int *len);
int					ft_double_exp(char *value_s, int exp_size);
void				ft_rounding_f(char *int_part, char *frac_part,
		t_struct *m, int exp);
void				ft_double_mantissa(char *s, int exp, t_struct *m);
void				ft_ldouble_mantissa(char *s, int exp, t_struct *m,
		char *value_s);
void				ft_check_infnan(char *s, t_struct *m);
void				ft_check_linfnan(char *s, t_struct *m);
void				ft_buf_init_e(char *int_part, char *frac_part, t_struct *m);
void				ft_define_format(char *int_part, char *frac_part,
		t_struct *m, int exp);
int					ft_vspom4(char *buf, char *int_part,
		char *frac_part, t_struct *m);
void				ft_exp(int *len_ip, char *buf, int *len_buf);
void				ft_left_alignment(t_struct *m, char *buf, int *len_buf);
void				ft_right_alignment(t_struct *m, char *buf,
		int *len_buf, int *flag);
void				ft_vspomog(char *buf, int *len_buf, t_struct *m, int *flag);
int					ft_unbr_len(uintmax_t value, int base);
int					ft_uitoa_base_pf(int fd, uintmax_t value, int base, char x);
void				ft_kostyl(int verif, t_struct *list);
int					ft_kostyl2(const char *format, t_struct *list);
void				ft_kostyl3(int verif, t_struct *list);
void				ft_parse(const char *format, t_struct *list);
void				ft_printdat(const char *format, t_struct *list);
void				ft_printform(const char *format, t_struct *list);
void				ft_printw(t_struct *list, int nbrlen);
void				ft_print_udec(t_struct *m, unsigned long long int value,
		char *buf);
void				ft_pars_help(const char *format, t_struct *list);
void				ft_del(char **g_int_part, char **g_frac_part);
void				ft_init_fd(t_struct *list);

#endif
