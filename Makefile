CC := c++
CPPFLAGS := -Wall -Wextra -Werror -std=c++98 -g
TARGET := ./webserv
INCLUDES :=	-I./server \
			-I./responses
RM := rm -f
SRC_DIR :=
SOURCE :=	main.cpp \
			server/Server.cpp \
			responses/Response.cpp
SRC := $(addprefix $(SRC_DIR), $(SOURCE))
OBJ := $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(TARGET)

re: fclean all

.PHONY: all clean fclean re
