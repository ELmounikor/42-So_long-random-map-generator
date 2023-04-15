NAME = maze_maker

CC = g++

SRCS = maze_generator.cpp BFS_search.cpp

OBJS = $(SRCS:.cpp=.o)


CPPFLAGS = -Wall -Werror -O3

all : $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

run : all
	./$(NAME) $(CHUFL)

clean : 
	rm -rf $(OBJS)

fclean : clean
	rm -rf ../$(NAME)

re : fclean all



.PHONY: clean fclean re run