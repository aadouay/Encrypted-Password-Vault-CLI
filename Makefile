NAME      = password_vault
CXX       = c++
CXXFLAGS  = -std=c++98 -Wall -Wextra -Werror
CPPFLAGS  = -Iinclude
RM        = rm -f

SRC_DIR   = src
SRCS      = $(SRC_DIR)/main.cpp \
			$(SRC_DIR)/Crypto.cpp \
			$(SRC_DIR)/Utils.cpp

OBJS      = $(SRCS:.cpp=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

