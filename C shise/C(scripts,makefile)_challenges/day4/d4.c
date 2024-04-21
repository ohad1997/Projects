#include <stdio.h>
#include <stdlib.h>


int ft_iterative_factorial(int num)
{
    if(num < 0)
        return 0;

    int value = 1;
    for (int i = 2; i < num; i++)
        value = value*i;
    return value;
}

int ft_recurcive_factorial(int num)
{
    if(num < 0)
        return 0;
    if (num == 1)
        return 1;

    return (num *ft_recurcive_factorial(num -1)) ;
}
int ft_sqrt(int num)
{
    int sqrtnum = 1;
    int value = 1;
    for (int i = 1; sqrtnum < num; i++)
    {
        value = i;
        sqrtnum = i * i;
    }

    if (value * value > num)
        return 0;

    return value;
}
 int ft_is_prime(int num)
 {
    for (int i = 2; i < num && num > 0;)
    {
        int temp = num % i;
        if ((num % i) == 0)
            num = temp;
        
        if (num % i != 0)
            i++;
    }

    if (num > 0 & num != 1)
        return 1;
    
    return 0;
 }

 int ft_find_next_prime(int num)
 {
    for (int j = 1; 0 < 1; j++)
    {
        int next_prime = num +j;
            for (int i = 2; i < next_prime && next_prime > 0;)
            {
                int temp = next_prime % i;
                if ((next_prime % i) == 0)
                    next_prime = temp;
        
                if (next_prime % i != 0)
                    i++;
            }

        if (next_prime > 0 & next_prime != 1)
        return next_prime;
        
    }
    
    return 0;
 }








 int ft_8_queen_check_row(int* arr)
 {
    for (int j = 0; j < 8; ++j)
        for (int i = j+1; i < 8; ++i)
            if (arr[i] == arr[j] && i != j)
                return 0;

    return 1;
 }
 int ft_8_queen_check_diagonal(int* arr)
 {
    for (int j = 0; j < 8; ++j)
        for (int i = j+1; i < 8; ++i)
        {
            int is_equal1 = arr[i] - i == arr[j] - j;
            int is_equal2 = j != i;
            int is_equal3 = arr[i] + i == arr[j] + j;         
            if ( is_equal2 && (is_equal1 || is_equal3))
                return 0;
        }

    return 1;
 }

int ft_eight_queen_problem_recursion(int* arr, int solutions, int index)
{
    if (index == 8 && ft_8_queen_check_diagonal(arr) == 1 && ft_8_queen_check_row(arr) == 1)
        return 1;

    if (index == 8)
        return 0;

    int temp = 0;
    for (int i = 0; i < 8 ; i++)
    {
        arr[index] = i + 1;
        temp = temp + ft_eight_queen_problem_recursion(arr, solutions, index + 1);
    }
    solutions = solutions + temp;
    return solutions;
}

int ft_eight_queen_problem(void)
{
    int arr[8] = {0,0,0,0,0,0,0,0};
    int solutions = ft_eight_queen_problem_recursion(arr,0,0);
    return solutions;
}
void test()
{
    int arr1_solution[]   = {4,8,1,5,7,2,6,3};
    int arr2[]   = {1,3,6,8,7,4,2,5};
    int arr3[]   = {1,4,6,8,2,7,5,3};
    int arr4[]   = {1,2,3,4,5,6,7,1};
    int arr5[]   = {-1,3,2,1,4,8,5,7,6};
    // int[] arr6   = {-1,0,0,0,0,0,0,0,0}
    // int[] arr7   = {-1,0,0,0,0,0,0,0,0}
    // int[] arr8   = {-1,0,0,0,0,0,0,0,0}
    // int[] arr9   = {-1,0,0,0,0,0,0,0,0}
    // int[] arr10  = {-1,0,0,0,0,0,0,0,0}
    // int[] arr11  = {-1,0,0,0,0,0,0,0,0}
    // int[] arr12  = {-1,0,0,0,0,0,0,0,0}
    // int[] arr13  = {-1,0,0,0,0,0,0,0,0}
    // // int[] arr14  = {-1,0,0,0,0,0,0,0,0}
    // for (int i = 0; i < 9; ++i)
    // {
    printf("\n");
    printf("arr1 = %d",ft_8_queen_check_diagonal(arr4));
    // printf("arr1 = %d",ft_8_queen_check_row(arr4));
    // printf("arr2 = %d",ft_8_queen_check_diagonal(arr2));
    // printf("arr3 = %d",ft_8_queen_check_diagonal(arr3));
    // printf("arr4 = %d",ft_8_queen_check_diagonal(arr4));ba
    // printf("arr5 = %d",ft_8_queen_check_diagonal(arr4));
    // }

}
int main(int argc, char const *argv[])
{
    // test();
    printf("%d" ,ft_eight_queen_problem());
    return 0;
}