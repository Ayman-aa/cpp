NAME=PmergeMe

all : $(NAME)

$(NAME) : *.cpp
	@c++ -Wall -Wextra -Werror -g -std=c++98 *.cpp -o $(NAME)

clean :
	@rm -rf $(NAME)

fclean : clean

re : fclean all