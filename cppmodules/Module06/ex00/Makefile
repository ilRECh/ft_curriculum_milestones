.PHONY:
	all re fclean

OS		=	$(shell uname)
TARGET	=	convert
RM		=	rm -rf
FLAGS	=	-Wall -Wextra -Werror -c -std=c++98 -pedantic

ifeq ($(OS), Darwin)
CC		=	clang++
else ifeq ($(OS), Linux)
CC		=	g++
else
$(error cannot set proper compiler)
endif

HEADERS	=	Converter.hpp

SRC		=	main.cpp\
			Converter.cpp
			
OBJ		=	$(SRC:.cpp=.o)

%.o: %.cpp $(HEADERS)
	$(CC) $(FLAGS) $< -o $@

$(TARGET):	$(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

all: $(TARGET)

fclean: clean
	$(RM) $(TARGET)

clean:
	$(RM) $(OBJ)

re:	fclean all
