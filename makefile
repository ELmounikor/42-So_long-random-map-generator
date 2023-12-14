NAME = maze_maker

CC = @g++

SRCS = maze_generator.cpp BFS_search.cpp wall_carver.cpp

OBJS = $(SRCS:.cpp=.o)

CPPFLAGS = -O3 -std=c++11

.cpp.o:
	${CC} ${CPPFLAGS} -c $< -o $@

all : $(OBJS)
	@$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[1;93m   ╔═╗┌─┐    ┬  ┌─┐┌┐┌┌─┐   ┬─┐┌─┐┌┐┌┌┬┐┌─┐┌┬┐   ┌┬┐┌─┐┌─┐   ┌─┐┌─┐┌┐┌┌─┐┬─┐┌─┐┌┬┐┌─┐┬─┐\033[0m"
	@echo "\033[1;93m───╚═╗│ │    │  │ │││││ ┬───├┬┘├─┤│││ │││ ││││───│││├─┤├─┘───│ ┬├┤ │││├┤ ├┬┘├─┤ │ │ │├┬┘\033[0m"
	@echo "\033[1;93m   ╚═╝└─┘────┴─┘└─┘┘└┘└─┘   ┴└─┴ ┴┘└┘─┴┘└─┘┴ ┴   ┴ ┴┴ ┴┴     └─┘└─┘┘└┘└─┘┴└─┴ ┴ ┴ └─┘┴└─\033[0m"
	@echo "\033[1;93m USAGE : ./executable [type of maze : 1 or 2] [length] [width] [nbr of coins] [file name]\033[0m"
	@echo ""
	@echo "\033[1;93m when using type 2 maze it is better to have an odd number of rows and colloms because of\033[0m"
	@echo "\033[1;93m the generation algorithm behavior \033[0m"

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
