CC			:= cc
NAME 		:= push_swap
NAME_BONUS	:= checker
CFLAGS		:= -Wall -Werror -Wextra -g3 -O3
BIN			:= ./bin/
HEADER		:= ./include/
SOURCE		:=	0.main.c 9.errors.c \
				2.list_creation.c 1.validate_arguments.c \
				4.go_big.c 3.push.c 3.swap.c \
				3.rotate.c  3.rev_rotate.c \
				4.go_small.c 8.utils.c 5.costs_target.c \
				7.real_matematic.c 2.list_struct.c
OBJECTS		:= $(addprefix $(BIN),$(SOURCE:.c=.o))

SOURCE_BONUS:=	main_bonus.c push_bonus.c swap_bonus.c \
				rotate_bonus.c rev_rotate_bonus.c errors_bonus.c \
				list_creation_bonus.c validate_arguments_bonus.c \
				list_struct_bonus.c
OBJECTS_BONUS:= $(addprefix $(BIN),$(SOURCE_BONUS:.c=.o))

PRINTF		:= ./42_libft/Printf/libftprintf.a
LIBFT		:= ./42_libft/libft.a
42LIBS		:= $(PRINTF) $(LIBFT)

BLUE = \033[1;34m
RED=\033[0;31m
GREEN=\033[0;32m
END=\033[0m

all: $(42LIBS) $(BIN) $(NAME)

$(LIBFT):
	@printf "$(BLUE)Compiling Libft...$(END)\n"
	@make -C ./42_libft --no-print-directory

$(PRINTF):
	@printf "$(BLUE)Compiling Printf...$(END)\n"
	@make -C ./42_libft/Printf --no-print-directory

$(BIN):
	@mkdir -p $(BIN)

$(BIN)%.o: ./mandatory/%.c $(HEADER)ft_push_swap.h
	@printf "$(BLUE)Compiling $<...$(END)\n"
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

$(NAME): $(OBJECTS) $(HEADER)ft_push_swap.h
	@printf "$(BLUE)Compiling $(NAME)...$(END)\n"
	@$(CC) $(CFLAGS) $(OBJECTS) $(42LIBS) -o $(NAME)
	@printf "$(GREEN)$(NAME) compiled!$(END)\n"

bonus : $(42LIBS) $(BIN) $(NAME_BONUS)

$(BIN)%.o: ./s_bonus/%.c $(HEADER)checker.h
	@printf "$(BLUE)Compiling $<...$(END)\n"
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

$(NAME_BONUS): $(OBJECTS_BONUS) $(HEADER)checker.h
	@printf "$(BLUE)Compiling $(NAME_BONUS)...$(END)\n"
	@$(CC) $(CFLAGS) $(OBJECTS_BONUS) $(42LIBS) -o $(NAME_BONUS)
	@printf "$(GREEN)$(NAME_BONUS) compiled!$(END)\n"

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
	@printf "$(GREEN)All cleaned!$(END)\n"

re: fclean all

.PHONY: all clean fclean re