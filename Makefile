#* ************************************************************************** */
#*                                                                            */
#*                                                        :::      ::::::::   */
#*   Makefile                                           :+:      :+:    :+:   */
#*                                                    +:+ +:+         +:+     */
#*   By: jkrause <jkrause@student.42.us.org>        +#+  +:+       +#+        */
#*                                                +#+#+#+#+#+   +#+           */
#*   Created: 2017/04/18 03:42:42 by jkrause           #+#    #+#             */
#*   Updated: 2017/06/11 02:45:14 by jkrause          ###   ########.fr       */
#*                                                                            */
#* ************************************************************************** */
# ----------------- Version 1.3 --------------------- #

# ------------- Automated Configuration ------------- #
NAME = libftprintf.a  
CFLAGS = -g -Wall -Werror -Wextra -I includes -I libft/includes 

SRC = modules/parse_module.c \
modules/string_module.c \
modules/bufferwrite_module.c \
modules/asterisks_module.c \
modules/integer_module.c \
modules/format_module.c \
modules/memorywrite_module.c \
src/ft_printf.c \
src/module_manager.c \
libft/ft_strrchr.c \
libft/ft_putstr.c \
libft/ft_strcmp.c \
libft/ft_strlcat.c \
libft/ft_memcpy.c \
libft/ft_no.c \
libft/ft_ltostr_base.c \
libft/ft_is_whitespace.c \
libft/ft_memmove.c \
libft/ft_strsplit.c \
libft/ft_strncpy.c \
libft/ft_lstmap.c \
libft/ft_lstadd.c \
libft/ft_striter.c \
libft/ft_atol.c \
libft/ft_strstr.c \
libft/ft_isdigit.c \
libft/ft_putnbr.c \
libft/ft_memccpy.c \
libft/ft_strdel.c \
libft/ft_memchr.c \
libft/ft_bzero.c \
libft/ft_isalnum.c \
libft/ft_putstr_fd.c \
libft/ft_lstiter.c \
libft/ft_lstdelone.c \
libft/ft_toupper.c \
libft/ft_strcpy.c \
libft/ft_expandwrite.c \
libft/ft_lstnew.c \
libft/ft_strdup.c \
libft/ft_putnbr_fd.c \
libft/ft_striteri.c \
libft/ft_strmap.c \
libft/ft_putendl_fd.c \
libft/ft_memdel.c \
libft/ft_strnstr.c \
libft/ft_putchar.c \
libft/ft_isascii.c \
libft/ft_strlen.c \
libft/ft_strsub.c \
libft/ft_expandpad.c \
libft/ft_strnew.c \
libft/ft_memalloc.c \
libft/ft_putendl.c \
libft/ft_strncat.c \
libft/ft_strnchr.c \
libft/ft_itoa.c \
libft/ft_strncmp.c \
libft/ft_memcmp.c \
libft/ft_strtrim.c \
libft/ft_strequ.c \
libft/ft_putchar_fd.c \
libft/ft_memset.c \
libft/ft_isalpha.c \
libft/ft_itoa_base.c \
libft/ft_strcat.c \
libft/ft_tolower.c \
libft/ft_strnequ.c \
libft/ft_strjoin.c \
libft/ft_atoi.c \
libft/ft_strclr.c \
libft/ft_strmapi.c \
libft/ft_isprint.c \
libft/ft_lstdel.c \
libft/ft_strchr.c \
libft/ft_ishex.c \
 
OBJ = $(subst .c,.o, $(SRC))

# ------------------- Targets ----------------------- #

all: $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJ)
	/bin/rm -f $(NAME)
	ar rcs $(NAME) $(OBJ)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)
	
re: clean all 
test: $(NAME)
	gcc -Iincludes -Ilibft/includes test.c $(NAME) $(LIBFT_BIN) -o testprog
	./testprog

symbolmaker: $(NAME)
	find libft -type f -name "*.c" | grep -E "$$(nm -g libftprintf.a | grep -oE "(ft_.+)" | grep -v ft_printf | tr '\n' '|'| sed -e 's/.$$//g')" > symbolincludes.txt
