typedef struct s_stock_par{
	int length;
	char* arr;
} array;



struct s_stock_par *ft_params_to_tab(int ac, char **av)
{
	array arguments_arr;

	arguments_arr.length = ac + 1;
	
}