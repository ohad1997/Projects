HEADERFILES=ft_opp.h
CFILES=ex9.c
EXEC=$(patsubst %.c,%,$(CFILES))
HEADERPATH=/home/ohad/Documents/cprojects/day10/ex9

all: $(EXEC)

%: %.c 
	@gcc -o $@ $< -I.

clean:
	rm $(EXEC)