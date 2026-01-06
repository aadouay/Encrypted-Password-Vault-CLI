NAME     = dec
CXX      = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
RM       = rm -f

SRC      = dec.cpp
OBJ      = $(SRC:.cpp=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

