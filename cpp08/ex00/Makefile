NAME = easyfind
CC = c++
RM = rm -f
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = src/main.cpp
OBJ= $(patsubst %.cpp, %.o,$(SRC))

all:
	make $(NAME)

%.o: %.c
	c++ -c $(FLAGS) -g -o $@ $<

$(NAME): $(OBJ)
	c++ $(FLAGS) $(OBJ) -g -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: clean all

.PHONY: all clean fclean re