################################################################################
######                             PROPERTIES                             ######
################################################################################

CXX			= c++
NAME		= Brain
RM			= rm -rf

SRCS_DIR	= src
OBJS_DIR	= obj

CXXFLAGS	= -Wall -Wextra -Werror -MP -MD -std=c++98 -g -Wshadow -Wno-shadow -pedantic

SRCS    = \
		$(SRCS_DIR)/Animal.cpp \
		$(SRCS_DIR)/Cat.cpp \
		$(SRCS_DIR)/Dog.cpp \
		$(SRCS_DIR)/Brain.cpp \
		$(SRCS_DIR)/main.cpp

OBJS	= $(SRCS:${SRCS_DIR}/%.cpp=${OBJS_DIR}/%.o)
DEPS	= $(OBJS:%.o=%.d)

################################################################################
######                               RULES                                ######
################################################################################

all		: $(NAME)

run		: re
		@clear
		@valgrind --leak-check=full ./${NAME};
		@$(RM) $(OBJS_DIR) $(NAME)

test	: re
		@clear
		@.valgrind -s /${NAME};
		@$(RM) $(OBJS_DIR) $(NAME)

$(NAME)	: $(OBJS)
		$(CXX) -o $(NAME) $^

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.cpp
		@mkdir -p $(dir $@)
		${CXX} ${CXXFLAGS} -c $< -o $@

clean	:
		$(RM) $(OBJS_DIR)

fclean	:
		$(RM) $(OBJS_DIR) $(NAME)

re		: fclean all

-include $(DEPS)

.PHONY: all clean fclean re run
