#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void ft_putchar(char c)
{
    write(0,&c,1);
}

void ft_putstr(char* str)
{
    char* adress = str;
    int size = 0;
    for (char* i = adress; *i != '\0'; i++)
        size++;

    for (char* j = adress + size -1; j > adress; j--, adress++)
    {
        char temp = *j;
        *j = *adress;
        *adress = temp; 
    }
    for (char* i = str; *i != '\0'; i++)
        ft_putchar(*i);
    
}
 int ft_numChar(char* str)
 {
    if (*str - 47 > 0 || *str - 58 < 9)
        return (*str - 48);
    return -1;
 }

 int ft_atoi(char* str)
{
    if (ft_numChar(str) == -1)
        return 0;

    int Val = 0;
    for (char* j = str; *j != '\0'; j++)
        Val = ((Val * 10) + ft_numChar(j));

    return Val;
}
void ft_sort_array(int *arr, int size)
{   
    for (int* i = arr; i <  arr + size -1 ; i++)
    {
        for (int* j = arr; j < arr + size -1; j++)
        {
            if (*j > *(j+1))
            {
                int temp = *j;
                *j = *(j+1);
                *(j+1) = temp;
            }
        }
    }
}
int main()
{
    int arr[] = {3,5,6,2,6,3,4,5,6,7,8,9,10,234,-44,52,-1,-9,675};
    for (int i = 0; i < 19; i++)
        printf("%d,",arr[i]);

    ft_sort_array(arr,19);
    printf("\n");
    for (int i = 0; i < 19; i++)
        printf("%d,",arr[i]);

    return 0;
}