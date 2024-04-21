#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>



void ft_foreach(int* tab, int length, void (*f)(int))
{
	int i = 0;

	while(i < length)
	{
		f(tab[i]);
		++i;
	}
}
void f (int num)
{
  ++num;
}

int main(int argc, char const *argv[])
{
	int arr[] = {2,3,4};
	ft_foreach(arr, 3, &f);

	return 0;
}
