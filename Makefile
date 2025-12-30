NAME    = password_manager
CPP     = c++
FLAGS   = -std=c++98 -Wall -Wextra -Werror
RM      = rm -rf

SRC     = src/main.cpp \
          src/Vault.cpp \
          src/PasswordEntry.cpp \
          src/Crypto.cpp \
          src/Utils.cpp \

OBJ     = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(FLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean
