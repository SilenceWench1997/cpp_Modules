NAME	=	ex03

CC		= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98 #-fsanitize=address -g
RM		= rm -rf

OBJ_DIR	= obj
SRC_DIR = ./
SRC		= main.cpp AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp Bezdna.cpp
OBJ		= $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC))

HEADERS = AMateria.hpp Ice.hpp Cure.hpp ICharacter.hpp Character.hpp MateriaSource.hpp IMateriaSource.hpp Bezdna.hpp

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
