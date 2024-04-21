#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>



int main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("no files to read");
		return 0;
	}
	
	char content[255];
	
	int i = 1;

	while(i < argc)
	{
		errno = 0;
		int fd = open(argv[i], O_RDONLY);
		int file_size = read(fd,content, 255);
		int lines_amount = 0;
		int j = 0;

		while(file_size > 0)
		{
			while(j < file_size)
			{
				if (content[j] == '\n')
					++lines_amount;
				
				++j;
			}

			switch(errno)
			{
				case 1: printf("Operation not permitted"); break;
				case 2: printf("No such file or directory"); break;
				case 4: printf("Interrupted system call"); break;
				case 5: printf("I/O error"); break;
				case 8: printf("Exec format error"); break;
				case 9: printf("Bad file number"); break;
				case 11: printf("Try again"); break;
				case 12: printf("Out of memory"); break;
				case 13: printf("Permission denied"); break;
				return 0;
			}

			if (file_size < 255)
				content[file_size] = 0;

			printf("%s",content);
			file_size = read(fd,content, 255);
			j = 0;
		}

			

		close(fd);

		++i;
	}

	return 0;
}
