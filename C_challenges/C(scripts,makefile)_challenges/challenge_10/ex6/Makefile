
CFILES=ex6.c
EXEC=$(patsubst %.c,%,$(CFILES))

all: $(EXEC)

%: %.c
	gcc -g $^ -o $@


clean:
	rm $(EXEC)

