all : generate

generate : *.cpp
	@c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o generate

clean :
	@rm -rf generate

re : clean all