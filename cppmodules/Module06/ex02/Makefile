.PHONY:
	all re fclean

OS		=	$(shell uname)
TARGET	=	identify
RM		=	rm -rf
FLAGS	=	-Wall -Wextra -Werror -c -std=c++98 -pedantic

ifeq ($(OS), Darwin)
CC		=	clang++
else ifeq ($(OS), Linux)
CC		=	g++
else
$(error cannot set proper compiler)
endif

HEADERS	=	

SRC		=	main.cpp
			
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

test:
	make
	./identify
	sleep 1
	./identify
	sleep 1
	./identify
	sleep 1
	./identify
	sleep 1
	./identify
	sleep 1

re:	fclean all
