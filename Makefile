CC := cc
NAME := push_swap
CFLAGS	:= -Wall -Werror -Wextra -g3
BIN := ./bin/
SOURCE := ./mandatory/0.main.c ./mandatory/9.errors.c \
			./mandatory/2.list_creation.c ./mandatory/1.validate_arguments.c \
				./mandatory/4.go_big.c ./mandatory/3.push.c ./mandatory/3.swap.c \
					./mandatory/3.rotate.c  ./mandatory/3.rev_rotate.c \
						./mandatory/4.go_small.c ./mandatory/8.utils.c ./mandatory/5.costs_target.c \
							./mandatory/7.real_matematic.c ./mandatory/2.list_struct.c\

HEADER	:= -I ./include/

PRINTF:= ./42_libft/Printf/libftprintf.a
LIBFT:= ./42_libft/libft.a
42LIBS:= $(PRINTF) $(LIBFT)
OBJECTS := ${SOURCE:sources/%.c=$(BIN)%.o}

BLUE = \033[1;34m
RED=\033[0;31m
GREEN=\033[0;32m
END=\033[0m

all: $(LIBFT) $(PRINTF) $(BIN) $(NAME)

$(LIBFT):
	@printf "$(BLUE)Compiling Libft...$(END)\n"
	@make -C ./42_libft --no-print-directory

$(PRINTF):
	@printf "$(BLUE)Compiling Printf...$(END)\n"
	@make -C ./42_libft/Printf --no-print-directory

$(BIN):
	@mkdir -p $(BIN)

$(BIN)%.o: sources/%.c
	@printf "$(BLUE)Compiling $<...$(END)\n"
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADER)

$(NAME): $(OBJECTS)
	@printf "$(BLUE)Compiling $(NAME)...$(END)\n"
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) $(42LIBS) $(HEADER)
	@printf "$(GREEN)$(NAME) compiled!$(END)\n"

clean:
	@printf "$(RED)Cleaning...$(END)\n"
	@make -C ./42_libft/Printf clean --no-print-directory
	@make -C ./42_libft clean --no-print-directory
	@rm -rf $(BIN)

fclean: clean
	@printf "$(RED)Cleaning...$(END)\n"
	@make -C ./42_libft/Printf --no-print-directory fclean
	@make -C ./42_libft --no-print-directory fclean
	@rm -rf $(NAME)
	@printf "$(GREEN)All cleaned!$(END)\n	"

re: fclean all

.PHONY: all clean fclean re