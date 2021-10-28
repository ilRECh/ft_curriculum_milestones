.PHONY:
	all re fclean

OS		=	$(shell uname)
TARGET	=	Interface
RM		=	rm -rf
FLAGS	=	-Wall -Wextra -Werror -c -std=c++98 -pedantic

ifeq ($(OS), Darwin)
CC		=	clang++
else ifeq ($(OS), Linux)
CC		=	g++
else
$(error cannot set proper compiler)
endif

HEADERS	=	AMateria.hpp\
			Character.hpp\
			Cure.hpp\
			Ice.hpp\
			ICharacter.hpp\
			IMateriaSource.hpp\
			MateriaSource.hpp

SRC		=	main.cpp\
			AMateria.cpp\
			Character.cpp\
			Cure.cpp\
			Ice.cpp\
			MateriaSource.cpp
			
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
