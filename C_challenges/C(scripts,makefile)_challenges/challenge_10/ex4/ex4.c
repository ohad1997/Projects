#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define True 1
#define False 0


int ft_count_if(char** tab, int (*f)(char*))
{
	int i = 0;
	int count = 0;

		while(tab[i])
		{
			if (f(tab[i]))
				++count;

			++i;
		}

	return count;
}


int func (char* chr)
{
  return ++chr;
}

int main(int argc, char const *argv[])
{

	return 0;
}