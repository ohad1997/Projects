#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>



void ft_putchar(char c)
{
	if (c <= 31 || c >= 127 )
		return;

    write(0,&c,1);
}



void ft_swap(int* num1, int* num2)
{
//	if (*num1 == NULL || *num2 == NULL)
//		return;

	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}



void ft_putstr(char* str)
{
	int i = 0;

	while(str[i] != '\0')
	{
		if (str[i] <= 31 || str[i] >= 127 )
			return;
		i++;
	}

	i = 0;

	while(str[i] != '\0')
	{
		write(0,(str + i),1);
		i++;
	}
}




int ft_strlen(char* arr)
{
	int i = 0;

	while(arr[i] != '\0')
	{
		if (arr[i] <= 31 || arr[i] >= 127 )
			return -1;
		i++;
	}

	int result = 0;

	if (arr != NULL)
	{
		while(arr[result] != '\0')
			result++;
	}
	else
		return (-1);

	return (result);
}




int ft_strcmp(char* str1, char* str2)
{
	int value1 = 0;
	int value2 = 0;
	int i = 0;

	int str1_end = 0;
	int str2_end = 0;

	while(str2_end == 0 || str1_end == 0)
	{
		if (str1[i] == '\0')
			str1_end = 1;
		if (str2[i] == '\0')
			str2_end = 1;

		if (str1_end == 0)
			value1 = value1 + (int) str1[i];

		if (str2_end == 0)
			value2 = value2 + (int) str2[i];

		i++;
	}

	if (value1 > value2)
		return -1;

	if (value1 < value2)
		return 1;

	if (value1 == value2)
		return 0;

	return 214800000;
}
