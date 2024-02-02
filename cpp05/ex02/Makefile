CXX			= c++

NAME		= AForm

RM			= rm -rf

SRCS_DIR	= src

OBJS_DIR	= obj

CXXFLAGS	= -Wall -Wextra -Werror -MP -MD -std=c++98 -g

SRCS    = \
			${SRCS_DIR}/main.cpp \
			${SRCS_DIR}/Bureaucrat.cpp \
			${SRCS_DIR}/AForm.cpp \
			${SRCS_DIR}/PresidentialPardonForm.cpp \
			${SRCS_DIR}/ShrubberyCreationForm.cpp \

OBJS	= $(SRCS:${SRCS_DIR}/%.cpp=${OBJS_DIR}/%.o)

DEPS	= $(OBJS:%.o=%.d)

all		: $(NAME)

run		: re
		@clear
		@valgrind ./${NAME};
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