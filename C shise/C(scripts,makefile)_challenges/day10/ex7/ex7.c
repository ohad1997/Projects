#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define True 1
#define False 0


int ft_strlen(char* str)
{
	int length = 0;
	while(str[length])
		++length;

	return length;
}

int get_max(int* arr, int length)
{
	int i = 1;
	int result = arr[0];
	while(i < length)
	{
		if (result < arr[i])
		{
			result = arr[i];
		}
	}
	return result;
}

void arr_initilize(int* arr, int length)
{
	int i = 0;

	while(i < length)
	{
		arr[i] = 0;
		++i;
	}
}

void counting_arr_build(char* arr_to_sort, int arr_sort_length, int* counting_arr ,int length_counting_arr)
{
	int i = 0;
	int j = 0;
	int index = 0;

	while(i < arr_sort_length)
	{
		counting_arr[arr_to_sort[i]] = counting_arr[arr_to_sort[i]] + 1;
		++i;
	}

	while(j < length_counting_arr + 1)
	{
		index = index + counting_arr[j];
		counting_arr[j] = index;
		++j;
	}
}

char* counting_sort(char* str)
{	
	int length = ft_strlen(str);
	int length_counting_arr = '~' + 1;
	int counting_arr['~' + 1];
	char* sorted_arr = malloc(sizeof(int) * length);
	int i = 0;
	int j = 0;

	arr_initilize(counting_arr, length_counting_arr);
	counting_arr_build(str, length, counting_arr, length_counting_arr);

	i = length - 1;
	j = length_counting_arr - 1;
	while(j - 1 > 0 && i > -1 && counting_arr[j] != 0)
	{
		if (!(counting_arr[j - 1] < counting_arr[j]))
		{
			--j;
		}
		else 
		{
			sorted_arr[i] = j;
			--i;
			--counting_arr[j];
		}
	}

	return sorted_arr;

}

char** radix_sort(char** tab, int* sizes, int sizes_length)
{
	int length = ft_strlen(tab);
	char** sorted_arr = malloc(length + 1);
	char* temp_arr = malloc(length + 1);
	int i = 0;
	int j = 0;
	int max_num = get_max_num(sizes,sizes_length);
	char temp = '0';

	while(i < max_num)
	{
		j = 0;
		while(tab[j])
		{
			if (j > sizes[i])
				temp = (char)('~' + 1);
			else
				temp = tab[j][i];

			temp_arr[j] = temp;
		}

	}	

	return sorted_arr;
}

void ft_sort_wordtab(char** tab)
{
	int length = ft_strlen(tab);
	int* sizes = malloc(sizeof(int)*(length + 1));
	char** result = malloc(length + 1);
	result[length] = 0;
	sizes[length] = 0;
	int i = 0;

	while(i < length)
	{
		sizes[i] = ft_strlen(tab[i]);
		++i;
	}
	result = radix_sort(tab, sizes, length + 1);

	i = 0;
	while(i < length)
	{
		tab[i] = result[i];
	}

}





// int* counting_sort(int* arr, int length)
// {
// 	int length_counting_arr = '~' + 1;
// 	int counting_arr['~' + 1];
// 	int* sorted_arr = malloc(sizeof(int) * length);
// 	int i = 0;
// 	int j = 0;

// 	arr_initilize(counting_arr, length_counting_arr);
// 	counting_arr_build(arr, length, counting_arr, length_counting_arr);

// 	i = length - 1;
// 	j = length_counting_arr - 1;
// 	while(j - 1 > 0 && i > -1 && counting_arr[j] != 0)
// 	{
// 		if (!(counting_arr[j - 1] < counting_arr[j]))
// 		{
// 			--j;
// 		}
// 		else 
// 		{
// 			sorted_arr[i] = j;
// 			--i;
// 			--counting_arr[j];
// 		}
// 	}

// 	return sorted_arr;

// }

int main(int argc, char const *argv[])
{
	char arr[] = "aivnfkdzepcjskg";
	printf("before sorting:");

	for (int i = 0; i < 15 ; ++i)
	{
		printf("%c",arr[i]);
	}
	char* arr2 = counting_sort(arr);
	printf("\nafter sorting:");
	for (int i = 0; i < 15 ; ++i)
	{
		printf("%c",arr2[i]);
	}

	return 0;
}

