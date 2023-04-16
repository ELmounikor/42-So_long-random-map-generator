NAME = maze_maker

CC = @g++

SRCS = maze_generator.cpp BFS_search.cpp

OBJS = $(SRCS:.cpp=.o)

CPPFLAGS = -Wall -Werror -O3

.cpp.o:
	${CC} ${CPPFLAGS} -c $< -o $@

all : $(OBJS)
	@$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[1;93m   ╔═╗┌─┐    ┬  ┌─┐┌┐┌┌─┐   ┬─┐┌─┐┌┐┌┌┬┐┌─┐┌┬┐   ┌┬┐┌─┐┌─┐   ┌─┐┌─┐┌┐┌┌─┐┬─┐┌─┐┌┬┐┌─┐┬─┐\033[0m"
	@echo "\033[1;93m───╚═╗│ │    │  │ │││││ ┬───├┬┘├─┤│││ │││ ││││───│││├─┤├─┘───│ ┬├┤ │││├┤ ├┬┘├─┤ │ │ │├┬┘\033[0m"
	@echo "\033[1;93m   ╚═╝└─┘────┴─┘└─┘┘└┘└─┘   ┴└─┴ ┴┘└┘─┴┘└─┘┴ ┴   ┴ ┴┴ ┴┴     └─┘└─┘┘└┘└─┘┴└─┴ ┴ ┴ └─┘┴└─\033[0m"
	@echo "\033[1;93m                        USAGE : ./executable [length] [width] [nbr of coins] [file name]\033[0m"

USAGE : ./executable [length] [width] [nbr of coins] [file name]
run : all
	$(NAME)

clean : 
	@rm -rf $(OBJS)
	@echo "\033[1;94m	* files deleted *\033[0m"

fclean : clean
	@rm -rf $(NAME)
	@echo "\033[1;94m	ʕ•́ᴥ•̀ʔっ\033[0m"

re : fclean all



.PHONY: clean fclean re run