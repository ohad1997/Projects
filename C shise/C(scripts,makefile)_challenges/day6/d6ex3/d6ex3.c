#include <stdio.h>

int main(int argc, char* argv[])
{
	int i = argc - 1;

	while (i > 0)
	{
		printf("%s\n", argv[i]);
		--i;
	}

	return 0;
}