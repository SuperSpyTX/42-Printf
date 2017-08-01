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
divert(-1)

# ------------- Real Configuration ------------------ #

define(MK_NAME, libftprintf)
define(MK_ISLIB, 1)
define(MK_INCLUDE_DIRS, includes)
define(MK_SRC_DIRS, modules src)
define(MK_DEBUG, 1)

define(MK_LIBFT, 1)
define(MK_LIBFT_REMAKE_ON_RE, 0)
define(MK_LIBFT_DIR, libft)
define(MK_LIBFT_INCLUDE_DIR, includes)
define(MK_LIBFT_BIN, libft.a)

# ------------ Automated Variables ------------------ #
define(MK_AUTO_SRC_DIR, patsubst(MK_SRC_DIRS,` ',`````,'''''))
pushdef(`MK_AUTO_SRC_DIR', ifelse(MK_SRC_DIRS,.,.,{MK_AUTO_SRC_DIR}))
define(MK_AUTO_SRC, esyscmd(bash -c 'find MK_AUTO_SRC_DIR -type f -name "*.c" | sed -e "s/$/ \\\/g"'))
define(MK_AUTO_ISLINUX, ifelse(esyscmd(uname -s | tr -d '\n'), `Darwin', 0, 1))
define(MK_AUTO_SRC_DIR, patsubst(MK_SRC_DIRS,` ',```,'''))
define(MK_AUTO_INCLUDE_DIR, -I patsubst(MK_INCLUDE_DIRS,` ',``` -I '''))
define(MK_AUTO_COMPILER,ifelse(MK_AUTO_ISLINUX, 1, clang, gcc))

divert(0)
# ------------- Automated Configuration ------------- #
NAME = ifelse(MK_ISLIB, 1, MK_NAME.a, MK_NAME) divert(-1)
ifelse(MK_LIBFT, 1,divert(0)
LIBFT_DIR = MK_LIBFT_DIR/
LIBFT_BIN = $(LIBFT_DIR)MK_LIBFT_BIN) divert(0)
CFLAGS = ifelse(MK_DEBUG, 1,-g) ifelse(MK_AUTO_ISLINUX, 1,-fPIC )-Wall -Werror -Wextra MK_AUTO_INCLUDE_DIR dnl
ifelse(MK_LIBFT, 1,-I MK_LIBFT_DIR/MK_LIBFT_INCLUDE_DIR)

SRC = MK_AUTO_SRC
OBJ = $(subst .c,.o, $(SRC))

# ------------------- Targets ----------------------- #

all: ifelse(MK_LIBFT, 1,$(LIBFT_BIN) )$(NAME)

%.o: %.c
	MK_AUTO_COMPILER $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJ)
	ifelse(MK_ISLIB, 0,MK_AUTO_COMPILER $(OBJ) -o $(NAME) $(LIBFT_BIN),
	/bin/rm -f $(NAME)
	ar rcs $(NAME) $(OBJ))dnl

ifelse(MK_LIBFT,1,divert(0)
$(LIBFT_BIN):
	$(MAKE) -C $(LIBFT_DIR)
)dnl

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)
	ifelse(MK_LIBFT, 1,$(MAKE) -C $(LIBFT_DIR) fclean
	)dnl

re: ifelse(MK_LIBFT_REMAKE_ON_RE, 1,f)clean all
