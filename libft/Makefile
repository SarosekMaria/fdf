# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sassassi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/12 14:24:17 by sassassi          #+#    #+#              #
#    Updated: 2020/08/29 18:09:58 by sassassi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRC_NAME = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c\
	ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c\
	ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c\
	ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c\
	ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c\
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
	ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c\
	ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c\
	ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c\
	ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c\
	ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c\
	ft_putendl_fd.c ft_putnbr_fd.c ft_strrev.c ft_lstnew.c\
	ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c\
	ft_lstapend.c ft_lstsize.c ft_lstat.c ft_lstlast.c ft_btree_new_node.c\
	ft_btree_apply_prefix.c ft_btree_apply_infix.c ft_btree_apply_suffix.c\
	ft_printf.c ft_del.c ft_vspomog.c ft_left_alignment.c\
	ft_right_alignment.c ft_exp.c ft_vspom4.c ft_define_format.c\
	ft_buf_init_e.c ft_check_linfnan.c ft_check_infnan.c\
	ft_ldouble_mantissa.c ft_double_mantissa.c ft_rounding_f.c\
	ft_double_exp.c ft_division_str.c ft_pow.c ft_pow_str_2.c\
	ft_pow_str_10.c ft_sum_str_frac.c ft_overflow_digit_check.c\
	ft_help.c ft_parser.c ft_print_char.c ft_print_percent.c\
	ft_print_string.c ft_bitwise_shift.c ft_bitwise_shift_buf.c\
	ft_itoa_base.c ft_print_float.c ft_print_octal.c ft_print_hex.c\
	ft_print_udecimal.c ft_print_decimal.c ft_print_pointer.c\
	ft_buf_init_dioux.c ft_buf_init_float.c ft_buf_init_u.c\
	ft_buf_init_o.c ft_buf_init_d.c ft_buf_init_x.c ft_itoa_u.c\
	ft_itoa_s.c ft_if_hash.c ft_sum_str_int.c kostyliivelosipedy.c\
	ft_buf_init_inff.c ft_help_2.c ft_print_binar.c get_next_line.c
SRC_DIR = ./
OBJ_NAME = $(SRC_NAME:%.c=%.o)
OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_NAME))
INC_DIR = ../includes/
INC = -I $(INC_DIR)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ_DIR)*.o
	@ranlib $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $< $(INC)

clean:
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
