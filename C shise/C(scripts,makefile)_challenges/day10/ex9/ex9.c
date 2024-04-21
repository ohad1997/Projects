#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_opp.h"


#define True 1
#define False 0

int add (int num1, int num2) {return(num1 + num2);}
int sub (int num1, int num2) {return(num1 - num2);}
int mult (int num1, int num2) {return(num1 * num2);}
int division (int num1, int num2) {return(num1 / num2);}
int modulo (int num1, int num2){return(num1 % num2);}
int usage (int num1, int num2){printf("no, you donut! the only acceptable characters are: + - * / %%\n"); return 0;}

int atoii(char* chr)
{
	return ((int) *chr);
}


int main(int argc, char const *argv[])
{

	if(argc != 4)
		return 0;

	int value = atoii(argv[2]);

	switch(value)
	{
		case '+': printf("%d",g_opptab[1].opp(atoi(argv[1]),atoi(argv[3]))); break;
		case '-': printf("%d",g_opptab[0].opp(atoi(argv[1]),atoi(argv[3]))); break;
		case '*': printf("%d",g_opptab[2].opp(atoi(argv[1]),atoi(argv[3]))); break;
		case '/': printf("%d",g_opptab[3].opp(atoi(argv[1]),atoi(argv[3]))); break;
		case '%': printf("%d",g_opptab[4].opp(atoi(argv[1]),atoi(argv[3]))); break;	
	}
	
	if (value != '+' || value != '-' || value != '/' || value != '*' || value != '%')
		g_opptab[5].opp(atoi(argv[1]),atoi(argv[3]));

	return 0;
}
