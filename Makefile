
BINARY_NAME = containers_tester

SRCS_DIR = tests/

HEADERS_DIR = tests/

CONTAINER_TEMPLATES_DIRS = list/ map/ queue/ stack/ vector/

SRCS_NAMES = main.cpp \
			ListIteratorTestCase.cpp \
			ListTestCase.cpp \
			VectorTestCase.cpp \
			MapTestCase.cpp \
			StackTestCase.cpp \
			QueueTestCase.cpp \
			TestCase.cpp
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_NAMES))

OBJS = $(SRCS:.cpp=.o)

HEADERS = $(HEADERS_DIR)/*.hpp

CONTAINER_TEMPLATES = list/list.hpp\
						map/map.hpp\
						queue/queue.hpp\
						stack/stack.hpp\
						vector/vector.hpp

CC = clang++

COPTS = -Wall -Wextra -Werror -std=c++98 -g

.PHONY: all clean fclean re

all: $(BINARY_NAME)

$(BINARY_NAME): $(OBJS)
		$(CC) $(OBJS) -o $(BINARY_NAME)

%.o: %.c $(SRCS) $(HEADERS) $(CONTAINER_TEMPLATES)
	$(CC) $(COPTS) $(addprefix -I, $(HEADERS_DIR) $(CONTAINER_TEMPLATES_DIRS)) $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: all
	./$(BINARY_NAME)