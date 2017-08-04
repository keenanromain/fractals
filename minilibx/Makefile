#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2 -Wno-deprecated
all: $(NOM)

$(NOM):	$(OBJ)
	@echo "\033[01;36marchiving...\033[0m \n"
	@echo "\033[01;36m|  \/  (_)     (_) |    (_) |        \033[0m"
	@echo "\033[01;36m| \  / |_ _ __  _| |     _| |____  __\033[0m"
	@echo "\033[01;36m| |\/| | | '_ \| | |    | | '_ \\ \\/ /\033[0m"
	@echo "\033[01;36m| |  | | | | | | | |____| | |_) >  < \033[0m"
	@echo "\033[01;36m|_|  |_|_|_| |_|_|______|_|_.__/_/\\_\\ \033[0m"
	ar -r $(NOM) $(OBJ)
	ranlib $(NOM)

clean:
	@echo "\033[01;37mCleaning Minilibx...\033[0m"
	rm -f $(NOM) $(OBJ) *~
	rm -f mlx_app

re: clean all
