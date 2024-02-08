CC := cc
NAME := push_swap
CFLAGS	:= -Wall -Werror -Wextra -g3
BIN := ./bin/
SOURCE := ./sources/oi.c ./sources/0.main.c ./sources/9.errors.c \
			./sources/2.list_creation.c ./sources/1.validate_arguments.c \
				./sources/4.go_big.c ./sources/3.push.c ./sources/3.swap.c \
					./sources/3.rotate.c  ./sources/3.rev_rotate.c \
						./sources/4.go_small.c ./sources/8.utils.c ./sources/5.costs_target.c \
							./sources/7.real_matematic.c ./sources/2.list_struct.c\

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