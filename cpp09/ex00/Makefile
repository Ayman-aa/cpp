NAME=btc

all : $(NAME)

$(NAME) : *.cpp
	@c++ -Wall -Wextra -Werror *.cpp -o $(NAME)

clean :
	@rm -rf $(NAME)

fclean : clean

re : fclean all