NAME        := ex04
TEST_NAME   := tests

CXX         := c++
CXXFLAGS    := -Wall -Wextra -Werror -MMD -MP -std=c++98

SRC_DIR     := .
OBJ_DIR     := objects
TEST_OBJ_DIR := test_objects

SRCS        := main.cpp Replace.cpp
OBJS        := $(SRCS:%.cpp=$(OBJ_DIR)/%.o)
DEPS        := $(OBJS:.o=.d)

TEST_SRCS   := test_main.cpp Test.cpp Replace.cpp
TEST_OBJS   := $(TEST_SRCS:%.cpp=$(TEST_OBJ_DIR)/%.o)
TEST_DEPS   := $(TEST_OBJS:.o=.d)

.PHONY: all clean fclean re test

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@
	@echo "✅ Built $(NAME)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TEST_NAME): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) $(TEST_OBJS) -o $@
	@echo "✅ Built $(TEST_NAME)"

$(TEST_OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: $(TEST_NAME)
	@./$(TEST_NAME)

clean:
	rm -rf $(OBJ_DIR) $(TEST_OBJ_DIR)

fclean: clean
	rm -f $(NAME) $(TEST_NAME)

re: fclean all

-include $(DEPS)
-include $(TEST_DEPS)

.DELETE_ON_ERROR: