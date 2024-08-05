CXX = g++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = main.cpp zombieHorde.cpp Zombie.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = Moar_Brains

all: $(TARGET)

$(TARGET): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(TARGET)

.PHONY: all clean fclean
