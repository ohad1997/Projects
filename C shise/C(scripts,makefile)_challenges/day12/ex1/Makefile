
CFILES=ex1.c
EXEC=$(patsubst %.c,%,$(CFILES))

all: $(EXEC)

%: %.c
	gcc -g $^ -o $@

clean:
	rm $(EXEC)

fclean: clean
	


