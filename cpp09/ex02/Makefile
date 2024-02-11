NAME	=	PmergeMe
NAMEC	=	Checker

CC		= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98 -g #-fsanitize=address
RM		= rm -rf

OBJ_DIR	= obj
OBJ_DIR_C = objc

SRC_DIR = ./
SRC_DIR_C = ./

SRC		= main.cpp PmergeMeV.cpp PmergeMeL.cpp
SRC_C		= checker.cpp
OBJ		= $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC))
OBJ_C	= $(patsubst %.cpp, $(OBJ_DIR_C)/%.o, $(SRC_C))

HEADERS = PmergeMeV.hpp PmergeMeL.hpp

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	$(CC) $(CPPFLAGS) $(SRC) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) -c -o $@ $<

check : $(NAMEC)

$(NAMEC) : $(OBJ_C)
	$(CC) $(CPPFLAGS) $(SRC_C) -o $(NAMEC)

$(OBJ_DIR_C):
	mkdir -p $(OBJ_DIR_C)

$(OBJ_DIR_C)/%.o: $(SRC_DIR_C)/%.cpp | $(OBJ_DIR_C)
	$(CC) $(CPPFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ_DIR)
	$(RM) $(OBJ_DIR_C)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAMEC)

re: clean all

.PHONY: all clean fclean re
