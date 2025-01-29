#ifndef FT_OPP_H
#define FT_OPP_H

typedef int (*operator)(int , int);

typedef struct t_opp
{
	char* operation;
	operator opp; 
} t_opp;


int add (int num1, int num2);
int sub (int num1, int num2);
int mult (int num1, int num2);
int division (int num1, int num2);
int modulo (int num1, int num2);
int usage (int num1, int num2);

t_opp g_opptab[] =
{

	{"-", &sub},
	{"+", &add},
	{"*", &mult},
	{"/", &division},
	{"%%", &modulo},
	{"", &usage}
};

#endif




