BINARY_NAME = containers_tester

TEMPLATES = list/list.hpp\
			map/map.hpp\
			queue/queue.hpp\
			stack/stack.hpp\
			vector/vector.hpp

TEMPLATES_DIRS = $(dir $(TEMPLATES))

SRCS_DIR = tests/

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

HEADERS_DIR = tests/

HEADERS = $(HEADERS_DIR)/*.hpp

CC = clang++

COPTS = -Wall -Wextra -Werror -std=c++98 -g -c $(addprefix -I, $(HEADERS_DIR) $(TEMPLATES_DIRS))

.PHONY: all clean fclean re

all: $(BINARY_NAME)

$(BINARY_NAME): $(OBJS)
		$(CC) $(OBJS) -o $(BINARY_NAME)

%.o: %.cpp
	$(CC) $(COPTS)  $< -o $@

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(BINARY_NAME)

re: fclean all

run: all
	./$(BINARY_NAME)