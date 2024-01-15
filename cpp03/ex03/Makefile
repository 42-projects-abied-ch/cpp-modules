NAME    = DiamondTrap

CC      = c++

FLAGS   = -Wall -Wextra -Werror -std=c++98 -MP -MMD

RM      = rm -rf

SRC_DIR = src/

SRCS    = 	$(SRC_DIR)DiamondTrap.cpp \
			$(SRC_DIR)main.cpp \
			$(SRC_DIR)ScavTrap.cpp \
			$(SRC_DIR)FragTrap.cpp \
			$(SRC_DIR)ClapTrap.cpp

OBJ_DIR = obj

OBJ     = $(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)/%.o, $(SRCS))
DEP     = $(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)/%.d, $(SRCS))

.PHONY: all clean fclean re

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $^ -o $@ 

$(OBJ_DIR)/%.o: $(SRC_DIR)%.cpp
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

-include $(DEP)
