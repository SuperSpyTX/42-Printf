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
LIBFT_DIR = libft/
LIBFT_BIN = $(LIBFT_DIR)libft.a 
CFLAGS = -g -Wall -Werror -Wextra -I includes -I libft/includes

SRC = modules/parse_module.c \
modules/bufferwrite_module.c \
modules/integer_module.c \
modules/memes_module.c \
src/ft_printf.c \
src/module_manager.c \

OBJ = $(subst .c,.o, $(SRC))

# ------------------- Targets ----------------------- #

all: $(LIBFT_BIN) $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJ)
	/bin/rm -f $(NAME)
	ar rcs $(NAME) $(OBJ)

$(LIBFT_BIN):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	
re: clean all
