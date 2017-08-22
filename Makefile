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
CFLAGS =  -Wall -Werror -Wextra -I includes 

SRC = modules/parse_module.c \
modules/string_module.c \
modules/bufferwrite_module.c \
modules/asterisks_module.c \
modules/integer_module.c \
modules/format_module.c \
modules/memorywrite_module.c \
src/ft_printf.c \
src/module_manager.c \
 libft/ft_memcpy.c \
libft/ft_ltostr_base.c \
libft/ft_expandwrite.c \
libft/ft_strdup.c \
libft/ft_strlen.c \
libft/ft_strsub.c \
libft/ft_expandpad.c \
libft/ft_strnew.c \
libft/ft_memalloc.c \
libft/ft_memset.c \
libft/ft_strchr.c \

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

