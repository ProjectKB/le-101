# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/07 09:01:58 by rcepre       #+#   ##    ##    #+#        #
#    Updated: 2018/12/18 07:11:39 by loiberti    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libftprintf.a

CC= clang

CFLAGS= -Wall -Wextra -Werror -g

SRC_DIR = .

SRC = $(SRC_DIR)/list_tools.c \
	$(SRC_DIR)/parse_string.c \
	$(SRC_DIR)/stock_for_parsing.c \
	$(SRC_DIR)/parse_args.c \
	$(SRC_DIR)/fix_impossible_flag.c \
	$(SRC_DIR)/flag_plus_zero_aq.c \
	$(SRC_DIR)/field.c \
	$(SRC_DIR)/precision.c \
	$(SRC_DIR)/length_modifier.c \
	$(SRC_DIR)/transform_chain.c \
	$(SRC_DIR)/final_display.c \
	$(SRC_DIR)/length_modifier.c \
	$(SRC_DIR)/transform_chain.c \
	$(SRC_DIR)/final_display.c \
	$(SRC_DIR)/ft_printf.c \
	$(SRC_DIR)/flag_hash.c \

HEADER = ./printf.h
LIBFT_PATH = ./libft
LIBFT_OBJ = $(LIBFT_PATH)/*.o

OBJ_DIR = objects
OBJECT = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

####################################TEXT########################################
RED = \033[1;31m
OK  = \033[1;32m[OK]\n
WHITE = \033[0;29m
YELLOW = \033[1;33m
PINK = \033[1;35m
RM_PRINTF_OBJ = "$(PINK)printf :\t$(RED)rm $(PINK)objects\t\t$(WHITE)"
RM_LIB_OBJ = "\n$(YELLOW)libft:\t\t$(RED)rm $(YELLOW)objects\t\t$(WHITE)"
RM_LIB = "\t$(YELLOW)rm libft.a\t$(WHITE)"
RM_EXEC = "\t\t$(RED)rm $(PINK)exec\t\t\t$(WHITE)"
MAKE_PRINTF = "$(PINK)printf :\t$(RED)make $(PINK)printf\t\t$(WHITE)"
MAKE_LIB =  "\n$(YELLOW)libft :\t\t$(RED)make $(YELLOW)libft\t\t$(WHITE)"
####################################RULES######################################

$(NAME): $(OBJECT) $(HEADER)
	@(cd $(LIBFT_PATH) && make) > /dev/null
	@printf  $(MAKE_LIB)
	@printf "$(OK)"
	@ar rucs $(NAME) $(OBJECT) $(LIBFT_OBJ)
	@printf $(MAKE_PRINTF)
	@printf "$(OK)\n"

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@printf "\033[0;36m>>>\tCompiling: $? ..."
	@$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<
	@printf "   [ok]$(WHITE)\n"

clean:
	@printf $(RM_LIB_OBJ)
	@(cd $(LIBFT_PATH) && make $@) > /dev/null
	@printf "$(OK)"
	@printf $(RM_PRINTF_OBJ)
	@rm -rf $(OBJ_DIR)
	@printf "$(OK)"

fclean: clean
	@(cd $(LIBFT_PATH) && make $@) > /dev/null
	@printf $(RM_EXEC)
	@printf "$(OK)\n"
	@rm -rf $(NAME)

re: fclean all
	@(cd $(LIBFT_PATH) && make $@) > /dev/null

.PHONY: clean fclean
