##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## rush3
##

CC				=				g++
RM				=				rm -rvf
OUT				=				gkrellm

SRCS			=

SRCS_TESTS		=

CFLAGS			=				-W -Wall -Wextra
FLAGS			=				-lcriterion --coverage -g3 -O2 -lgcov -ggdb
OBJS			=				$(SRCS:.cpp=.o)
OBJS_TESTS		=				$(SRCS_TESTS:.cpp=.o)
OBJS_TESTS		+=				$(OBJS)

all : $(OBJS)
	$(CC) -o $(OUT) $(OBJS)

test : $(OBJS) $(OBJS_TESTS)
	$(CC) $(FLAGS) -o $(OUT) $(OBJS_TESTS)
	./$(OUT) --verbose
	$(RM) $(OBJS_TESTS)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(OUT)

re : fclean all

.PHONY : all clean fclean re test
