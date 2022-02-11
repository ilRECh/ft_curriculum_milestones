TARGET		:= test
CXX			:= clang++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++98
SRC			:= $(wildcard *.cpp)
OBJECTS		:= $(SRC:%.cpp=%.o)
INCLUDE		:= -I ./include

.PHONY: all clean fclean re

all: $(TARGET)

$(OBJ_DIR)/%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo $(CXX) $(CXXFLAGS) $(INCLUDE) $@

$(TARGET): $(OBJECTS)
	@$(CXX) $(CXXFLAGS) -o $(TARGET) $
	@echo $(CXX) $(CXXFLAGS) $@

clean:
	-@rm -rvf $(OBJ_DIR)/*

fclean: clean
	-@rm -rvf $(APP_DIR)/*

re			: clean all
