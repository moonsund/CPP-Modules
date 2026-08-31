NAME      := ex02
CXX       := c++
CXXFLAGS  := -Wall -Wextra -Werror -MMD -MP -std=c++98

SRC_DIR   := .
OBJ_DIR   := objects

SRCS      := main.cpp
OBJS      := $(SRCS:%.cpp=$(OBJ_DIR)/%.o)
DEPS      := $(OBJS:.o=.d)

.PHONY: all clean fclean re
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@
	@echo "✅ Built $(NAME)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.DELETE_ON_ERROR: