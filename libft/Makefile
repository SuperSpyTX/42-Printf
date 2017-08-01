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

NAME = libft.a  
CFLAGS = -g -Wall -Werror -Wextra -I includes 

SRC = ./ft_strrchr.c \
./ft_putstr.c \
./ft_strcmp.c \
./ft_strlcat.c \
./ft_memcpy.c \
./ft_no.c \
./ft_ltostr_base.c \
./ft_is_whitespace.c \
./ft_memmove.c \
./ft_strsplit.c \
./ft_strncpy.c \
./ft_lstmap.c \
./ft_lstadd.c \
./ft_striter.c \
./ft_atol.c \
./ft_strstr.c \
./ft_isdigit.c \
./ft_putnbr.c \
./ft_memccpy.c \
./ft_strdel.c \
./ft_memchr.c \
./ft_bzero.c \
./ft_isalnum.c \
./ft_putstr_fd.c \
./ft_lstiter.c \
./ft_lstdelone.c \
./ft_toupper.c \
./ft_strcpy.c \
./ft_expandwrite.c \
./ft_lstnew.c \
./ft_strdup.c \
./ft_putnbr_fd.c \
./ft_striteri.c \
./ft_strmap.c \
./ft_putendl_fd.c \
./ft_memdel.c \
./ft_strnstr.c \
./ft_putchar.c \
./ft_isascii.c \
./ft_strlen.c \
./ft_strsub.c \
./ft_strnew.c \
./ft_memalloc.c \
./ft_putendl.c \
./ft_strncat.c \
./ft_strnchr.c \
./ft_itoa.c \
./ft_strncmp.c \
./ft_memcmp.c \
./ft_strtrim.c \
./ft_strequ.c \
./ft_putchar_fd.c \
./ft_memset.c \
./ft_isalpha.c \
./ft_itoa_base.c \
./ft_strcat.c \
./ft_tolower.c \
./ft_strnequ.c \
./ft_strjoin.c \
./ft_atoi.c \
./ft_strclr.c \
./ft_strmapi.c \
./ft_isprint.c \
./ft_lstdel.c \
./ft_strchr.c \
./ft_ishex.c \

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
	

re: fclean all
