CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

PROG = main
SRC = main.c commandInput.c inventory.c location.c object.c objectCreation.c player.c playerManagement.c printing.c roomCreation.c random.c monster.c monsterCreation.c assertion.c
HDR = commandInput.h inventory.h location.h object.h objectCreation.h player.h playerManagement.h printing.h roomCreation.h random.h monster.h monsterCreation.h assertion.h
OBJ = $(SRC:.c=.o)

$(PROG): $(OBJ)
$(OBJ): $(HDR)
TAGS: $(SRC) $(HDR)
	etags $^
tags: $(SRC) $(HDR)
	ctags $^
.PHONY: clean
clean:
	$(RM) $(PROG) $(OBJ)