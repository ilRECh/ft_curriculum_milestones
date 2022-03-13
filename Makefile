TARGET		:= a.out
CXX			:= clang++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++98 -g
SRC			:= main.cpp
OBJECTS		:= $(SRC:%.cpp=%.o)
INCLUDES	:= $(wildcard include/*.hpp)\
				$(wildcard *.hpp)
INCLUDE		:= -I ./include

.PHONY: all clean fclean re

all: $(TARGET)

%.o: %.cpp $(INCLUDES)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo $(CXX) $(CXXFLAGS) $(INCLUDE) $@

$(TARGET): $(OBJECTS) $(INCLUDES)
	@$(CXX) $(CXXFLAGS) -o $(TARGET) $<
	@echo $(CXX) $(CXXFLAGS) $@

clean:
	-@rm -f $(OBJECTS)

fclean: clean
	-@rm -f $(TARGET)

re			: clean all
