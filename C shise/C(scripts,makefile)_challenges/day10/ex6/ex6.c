#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define True 1
#define False 0

int add (int num1, int num2) {return(num1 + num2);}
int sub (int num1, int num2) {return(num1 - num2);}
int mult (int num1, int num2) {return(num1 * num2);}
int division (int num1, int num2) {return(num1 / num2);}
int modulo (int num1, int num2){return(num1 % num2);}

int atoii(char* chr)
{
	return ((int) *chr);
}

int main(int argc, char const *argv[])
{
	int (*func[])(int,int) = {add,sub,mult,division,modulo};
	int result = 0;

	if(argc != 4)
		return 0;

	switch((atoii(argv[2])))
	{
	case '+': result = func[0](atoi(argv[1]),atoi(argv[3])); break;
	case '-': result = func[1](atoi(argv[1]),atoi(argv[3])); break;
	case '*': result = func[2](atoi(argv[1]),atoi(argv[3])); break;
	case '/': result = func[3](atoi(argv[1]),atoi(argv[3])); break;
	case '%': result = func[4](atoi(argv[1]),atoi(argv[3])); break;
	}

	printf("%d", result);
	return 0;
}
