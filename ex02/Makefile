NAME = COST
CC = c++
FLAGS = -Wall -Wextra -Werror
SRC = Base.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
all : $(NAME)
$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
%.o : %.cpp 
	$(CC) $(FLAGS) -c $< -o $@
clean : 
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)
re : fclean all



