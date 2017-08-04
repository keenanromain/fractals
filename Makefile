# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kromain <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/27 15:05:07 by kromain           #+#    #+#              #
#    Updated: 2017/04/28 14:28:58 by kromain          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = \
		main.c			\
		create.c		\
		handlers.c		\
		coordinates.c	\
		types.c			\
		coloring1.c		\
		coloring2.c		\
		hooks1.c		\
		hooks2.c		\
		modify.c

all: $(NAME)

$(NAME): lib mlx
	@echo "\033[01;36mCompiling...\033[0m"
	@echo "\033[01;36m_______  ______ _______ _______ _______  _____\033[0m"
	@echo "\033[01;36m|______ |_____/ |_____| |          |    |     | |\033[0m"
	@echo "\033[01;36m|       |    \_ |     | |_____     |    |_____| |_____\033[0m"
	@echo "\033[01;36m                                                                    *"
	@echo "                                                                                "
	@echo "                                                             **                 "
	@echo "                                                          ****** *              "
	@echo "                                                          ********              "
	@echo "                                                           *****                "
	@echo "                                                     *************** *          "
	@echo "                                                ***********************  ***    "
	@echo "                                            *   ****************************    "
	@echo "                                            ********************************    "
	@echo "                                            *********************************  *"
	@echo "                                          ************************************  "
	@echo "                           ** ******     ************************************   "
	@echo "                          *************  ************************************   "
	@echo "                         *************** ***********************************    "
	@echo "                     ******************************************************     "
	@echo " ************************************************************************       "
	@echo "                     ******************************************************     "
	@echo "                         *************** ***********************************    "
	@echo "                          *************  ************************************   "
	@echo "                           ** ******     ************************************   "
	@echo "                                          ************************************  "
	@echo "                                           *********************************   *"
	@echo "                                           ********************************     "
	@echo "                                           *   ****************************     "
	@echo "                                               ***********************  ***     "
	@echo "                                                    *************** *           "
	@echo "                                                           *****                "
	@echo "                                                         ********               "
	@echo "                                                         ****** *               "
	@echo "                                                            **                  "
	@echo "                                                                                "
	@echo "                                                                   *     \033[0m"
	@cd src && clang -Wall -Wextra -Werror -c $(SRCS) -g
	cd src && clang $(SRCS:.c=.o) -g -L../minilibx -lmlx -framework OpenGL -framework Appkit -L../libft -lft -o $(NAME)
	mv src/fractol .
	@echo "\033[01;39mFinished making Fractol. Available Makefile commands:\033[0m"
	@echo "\033[01;39m - make\033[0m"
	@echo "\033[01;39m - make clean\033[0m"
	@echo "\033[01;39m - make fclean\033[0m"
	@echo "\033[01;39m - make re\033[0m"

lib:
	@cd libft && make

mlx:
	@cd minilibx && make

clean:
	@cd libft && make clean
	@cd minilibx && make clean
	@echo "\033[01;39mCleaning Fractol...\033[0m"
	@cd src && /bin/rm -f $(SRCS:.c=.o)

fclean: clean
	@cd libft && make fclean
	@echo "\033[01;31mRemoved Archived Minilibx\033[0m"
	@/bin/rm -f $(NAME)
	@echo "\033[01;31mRemoved Compiled Fractol\033[0m"

re: fclean all
