#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define EVEN_MSG "i have an even number of arguments\n"
#define ODD_MSG "i have an odd number of arguments\n"
#define SUCCESS 1
typedef int t_bool;


int EVEN(int num)
{
	if (!(num % 2))
		return TRUE;

	return FALSE;
}