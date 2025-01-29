#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define True 1
#define False 0

int ft_any(char** tab, int (*f)(char*))
{
	int i = 0;

		while(tab[i])
		{
			if (f(tab[i]))
				return True;

			++i;
		}

	return False;
}

int f (char* chr)
{
  return ++chr;
}

int main(int argc, char const *argv[])
{

	return 0;
}

