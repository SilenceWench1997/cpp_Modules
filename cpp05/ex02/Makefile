NAME	=	ex01

CC		= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++11  #-fsanitize=address -g
RM		= rm -rf

OBJ_DIR	= obj
SRC_DIR = ./
SRC		= main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
OBJ		= $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC))

HEADERS = Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	$(CC) $(CPPFLAGS) $(SRC) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ_DIR) 

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
