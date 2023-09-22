NAME	= necessary_violence

CC		= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98 #-fsanitize=address -g
RM		= rm -rf

OBJ_DIR	= obj
SRC		= main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
OBJ		= $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC))

HEADERS = HumanA.hpp HumanB.hpp Weapon.hpp

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	$(CC) $(CPPFLAGS) $(SRC) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC) | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ_DIR) 

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
