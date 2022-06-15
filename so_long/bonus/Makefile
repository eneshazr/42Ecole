CC = gcc
FLAGS = -framework OpenGL -framework AppKit -L./minilibx -lmlx -glldb
BONUS = so_long_bonus
SRCS = *.c ../get_next_line/*.c ../libft/*.c Errors/*.c Events/*.c Graphics/*.c Init/*.c
INCLUDES = ../Includes/*.h

all:
	@echo "\033[1;36m - Compiling..."
	@make -C ../libft
	@$(CC) $(SRCS) -o $(BONUS) $(FLAGS)
	@echo "\033[1;32m     [OK]"

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx
	$(FLAGS)

clean:
	@echo "\033[1;35m[🧹Cleaning...🧹]"
	@rm -rf $(BONUS)
	@rm -rf $(BONUS).dSYM
	@make clean -C ../libft

fclean: clean
	@echo "\033[1;35m[🧹FCleaning...🧹]"
	@rm -rf $(BONUS)
	@rm -rf $(BONUS).dSYM
	@make fclean -C ../libft

re: fclean all

norm:
	@norminette $(SRCS)
	@norminette $(INCLUDES)

.PHONY: all clean fclean norm re