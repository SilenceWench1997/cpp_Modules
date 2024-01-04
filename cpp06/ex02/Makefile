NAME	=	identify

CC		= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98 #-fsanitize=address -g
RM		= rm -rf

OBJ_DIR	= obj
SRC_DIR = ./
SRC		= main.cpp Base.cpp functions.cpp
OBJ		= $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC))

HEADERS = Base.hpp A.hpp B.hpp C.hpp 

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
