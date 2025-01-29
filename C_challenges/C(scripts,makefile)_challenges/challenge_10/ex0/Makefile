

CFILES=d10ex0.c
OBJFILES=$(patsubst %.c,%.o,$(CFILES))
OUTPUT=libft.a

all: $(OUTPUT) #! builds all needed files



%.o: %.c
	gcc -c -o $@ $^

$(OUTPUT): $(OBJFILES)
	@#gcc -shared -o $@ $^
	@printf "Creating library: $@..."
	@ar -rcs $@ $^
	@printf "OK!\n"



clean:
	rm -rf $(BINARY) $(OBJFILES)

fclean: clean
	rm libft.a

re: fclean all
