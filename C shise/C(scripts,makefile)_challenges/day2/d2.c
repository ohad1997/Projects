#include <stdio.h>
#include <stdlib.h>


void ft_print_alphabet()
{
    printf("abcdefghijklmnopqrstuvwxyz"); 
}

void ft_print_reverse_alphabet()
{
    printf("zyxwvutsrqponmlkjihgfedcba"); 
}

void ft_is_negative(int num)
{
    if (num<0)
        printf("N");
    else
        printf("P");
}

void ft_print_comb()
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 1; j < 8; j++)
        {
            if (j > i)
                 for (int k = 2; k < 9; k++)
                {
                   if (k > j)
                      printf("%d%d%d,",i,j,k);
                }
        }
    }
}

void ft_print_comb2()
{
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (i< 10)
                printf("0%d ",i);

            else if(i > 10 | i == 10)
                printf("%d ",i);

            if (j< 10)
                printf("0%d,",j);

            else if(j > 10 | j == 10)
                printf("%d,",j);
            
        }
    }
}
void ft_putnbr(int num)
{
    printf("%d",num);
}

int numOfChars(int n)
{
    int num = 0;
    for (int i = 0; n > 0; i++)
    {
        n = n / 10;
        num = i;
    }
    return num;
    
}

void ft_print_combn(int n)
{
    if (n > 10 || n < 0)
    {
        printf("n has to be between 0 and 10");
        return;
    }
    int size = 1;

    for (int j = 0; j < n; j++)
        size = size*10;
    
    for (int i = 0; i < size; i++)
    {
        int crrNumSize = numOfChars(i);

        for (int k = 0; k < n-crrNumSize - 1; k++)
            printf("0");
        
        printf("%d, ", i);
    }
}

int main(int argc, char *argv[])
{
    ft_print_combn(3);
    return 0;
}