CC := cc
NAME := push_swap
CFLAGS	:= -Wextra -Wall -Werror -g3
BIN := ./bin/
SOURCE := ./sources/oi.c ./sources/main.c ./sources/errors.c \
			./sources/list_creation.c ./sources/validate_arguments.c \
				./sources/sort_bellow_5.c ./sources/instructions.c \
					./sources/go_big.c \

HEADER	:= -I ./include/

PRINTF:= ./Printf/libftprintf.a
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
	@make -C ./Printf --no-print-directory

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
	@make -C ./Printf clean --no-print-directory
	@make -C ./42_libft clean --no-print-directory
	@rm -rf $(BIN)

fclean: clean
	@printf "$(RED)Cleaning...$(END)\n"
	@make -C ./Printf --no-print-directory fclean
	@make -C ./42_libft --no-print-directory fclean
	@rm -rf $(NAME)
	@printf "$(GREEN)All cleaned!$(END)\n	"

re: fclean all

.PHONY: all clean fclean re