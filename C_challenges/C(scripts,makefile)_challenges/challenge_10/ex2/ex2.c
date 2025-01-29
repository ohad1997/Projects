#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>




int* ft_map(int* tab, int length, int (*f)(int))
{
	int i = 0;
	int* arr = malloc(sizeof(int) * (length + 1));

		while(i < length)
		{
			arr[i] = f(tab[i]);
			++i;
	}

	return arr;
}

int f (int num)
{
  return ++num;
}

int main(int argc, char const *argv[])
{
	int arr[] = {2,3,4};

	printf("before:");
	for (int i = 0; i < 3; ++i)
	{
		printf("%d",arr[i]);
	}

	int* arr2 = ft_map(arr, 3, &f);

	printf("\nafter:");
	for (int i = 0; i < 3; ++i)
	{
		printf("%d",arr2[i]);
	}
	return 0;
}

