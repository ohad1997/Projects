#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define True 1
#define False 0


int ft_is_sort(int* tab, int length, int (*f) (int, int))
{
	int i = 0;

	while(i + 1 < length)
	{
		if (!f(tab[i],tab[i + 1]))
			return False;

		++i;
	}

	return True;
}


int func (int num1, int num2)
{
	if (num1 > num2)
		return False;

	return True;

}

int main(int argc, char const *argv[])
{
	
	return 0;
}