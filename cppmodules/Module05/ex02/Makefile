.PHONY:
	all re fclean

OS		=	$(shell uname)
TARGET	=	Bureau
RM		=	rm -rf
FLAGS	=	-Wall -Wextra -Werror -c -std=c++98 -pedantic

ifeq ($(OS), Darwin)
CC		=	clang++
else ifeq ($(OS), Linux)
CC		=	g++
else
$(error cannot set proper compiler)
endif

HEADERS	=	Bureaucrat.hpp\
			Form.hpp\
			ShrubberyCreationForm.hpp\
			RobotomyRequestForm.hpp\
			PresidentialPardonForm.hpp

SRC		=	main.cpp\
			Bureaucrat.cpp\
			Form.cpp\
			ShrubberyCreationForm.cpp\
			RobotomyRequestForm.cpp\
			PresidentialPardonForm.cpp
			
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

test:
	@make
	@echo '<-------------------------- test 1 ------------------------------>'
	@./Bureau 1
	@echo '<-------------------------- test 2 ------------------------------>'
	@./Bureau 150
