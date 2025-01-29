#include <stdio.h>

int ft_strlen(char* str)
{
	int i = 0;

	while(str[i])
		++i;

	return i;
}

void ft_swap_pointer(char* arr[], int index1, int index2)
{
	char* temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}

int biggerstr(char* arr[], int index1, int index2)
{
	int i = 1;

	while(((arr[index1])[i] && (arr[index2])[i]))
	{
		if ((arr[index1])[i] > (arr[index2])[i])
			return index1;

		if ((arr[index1])[i] < (arr[index2])[i])
			return index2;

		++i;
	}

	if (ft_strlen(arr[index1]) > ft_strlen(arr[index2]))
		return index1;

	return index2;
}

void ft_sortascii(int size, char* arr[])
{
	int i = 1;
	int j = 1;

	while(i < size)
	{
		j = 1;

		while (j < size - 1)
		{
			if(biggerstr(arr,j,j + 1) > j)
				ft_swap_pointer(arr,j,j+1);
			++j;
		}
		++i;
	}
}


int main(int argc, char* argv[])
{
	int i = 1;

	ft_sortascii(argc, argv);


	while (i < argc)
	{
		printf("%s\n", argv[i]);
		++i;
	}

	return 0;
}