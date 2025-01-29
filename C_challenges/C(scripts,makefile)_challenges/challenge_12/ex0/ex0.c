#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	if(argc > 2)
	{
		printf("too many files");
		return 0;
	}

	if (argc < 2)
	{
		printf("no files to read");
		return 0;
	}
	
	char line[255];

	int fd = open(argv[1], O_RDONLY);
	read(fd,line, 255);
	printf("%s",line);
	close(fd);
	return 0;
}

