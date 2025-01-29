#include <stdio.h>

#define True 1
#define False 0


////////////////////////////////exercise 0////////////////////////////////

int ft_strlen(char* str)
{
	int i = 0;

	if (!str[0])
		return -1;

	while(str[i])
		++i;

	return i;

}

char *ft_strdup(char* str)
{
	int size = ft_strlen(str);
	char* dup = malloc(size + sizeof(char));
	int i = 0;

	if (!str[0])
		return NULL;

	while(i < size)
	{
		dup[i] = str[i];
		++i;
	}

	return dup;
}



///////////////////////////////exercise 1//////////////////////////////
int *ft_range(int min, int max)
{
	if (max <= min)
		return NULL;

	int size = max - min;
	int* arr = malloc(sizeof(int) * size + sizeof(int));
	int i = 0;

	while(i < size)
	{
		arr[i] = min + i;
		++i;
	}

	return arr;
}



//////////////////////////////exercise 2/////////////////////////////
int ft_ultimate_range(int** range, int min, int max)
{
	if (max <= min | *range == NULL)
	{
		**range = NULL;
		return 0;
	}

	int size = max - min;
	**range = malloc(sizeof(int) * size + sizeof(int));
	int i = 0;

	while(i < size)
	{
		*range[i] = min + i;
		++i;
	}

	return size;
}


////////////////////////////exercise 3//////////////////////////////


char *ft_concat_params(int argc, char **argv)
{
	if (!argc)
		return NULL;

	int size = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	char* str = NULL;

	while(i < argc)
	{
		size = size + ft_strlen(argv[i]);
		++i;
	}

	str = malloc(size + sizeof(char) + argc);
	i = 0;
	j = 0;
	k = 0;

	while(i < argc)
	{
		j = 0;

		while(argv[i][j])
		{
			str[k] = argv[i][j];
			++k;
			++j;
		}

		str[k] = '\n';
		++k;
		++i;
	}
	str[k] = 0;

	return str;
}



///////////////////////////////exercise 4////////////////////////////

char **ft_split_whitespaces(char* str)
{
	if (*str == NULL)
		return NULL;
	int i = 0;
	int j = 0;
	int word_Num = 0;

	while(str[i])
	{
		if (str[i] == ' ' || str[i] == '\n' || str[i] == '	' )
			++word_Num;
		++i;
	}

	int* words_char_num = malloc(sizeof(int) * word_Num + sizeof(int));
	char** result = malloc(word_Num + sizeof(int));
	result[word_Num + 1] = 0;
	i = 0;
	j = 0;
	word_Num = 0;

	while(str[i])
	{
		if (str[i] == ' ' || str[i] == '\n' || str[i] == '	' )
		{
			j = 0;
			++word_Num;
		}
			
		++j;
		++i;
	}

	i = 0;
	j = 0;
	word_Num = 0;
	result[0] = malloc(words_char_num[0] + sizeof(char));

	while(str[i])
	{
		if (str[i] == ' ' || str[i] == '\n' || str[i] == '	' )
		{
			result[word_Num][j] = 0;
			j = 0;
			++word_Num;
			result[word_Num] = malloc(words_char_num[0] + sizeof(char));

		}

		else if (j < words_char_num[word_Num])
			result[word_Num][j] = str[i];
			
		++j;
		++i;
	}

	return result;

}



///////////////////////////////exercise 5///////////////////////////////


void ft_print_word_tables(char** tab)
{
	int i = 0;
	
	if (!*tab)
		return;

	while(tab[i])
	{
		printf("%s\n", tab[i]);
		++i;
	}
}



/////////////////////////////////exercise 6/////////////////////////////////


int is_base(char* base)
{
	int i = 0;
	int size = ft_strlen(base);


	while(i < size)
	{
		if (i < 10 && base[i] != (char)(i + 48))
			return False;

		else if (i > 9 && base[i] != (char) (i + 55))
			return False;
		i++;
	}

	return True;
}


char ft_base_char(int num, int base)
{
	if (base < 2)
		return '\0';

	char result = '0';

	if (base < 11 || num < 10)
		result = (char) (num + 48);

	else
		result = (char) (num + 55);

	return result;
}



int is_num(char* str, int base)
{
	int i = 0;

	if (*str == '+' || *str == '-')
		str++;

	while(i < ft_strlen(str))
	{
		if (str[i] < '0' || str[i] > 'F' || str[i] - '0' > base)
			return False;

		i++;
	}
	return True;
}

int ft_divisiontimes(int num, int base)
{
	int i = 0;
	if (num < 0)
		num = num* - 1;

	while(num > 0)
	{
		num = num  / base;
		i++;
	}
	return i;
}


int get_max_num(int base, int size)
{
	int i = 0;
	int result = 0;

	while(i < size)
	{
		result = result + base;
		base = base * (base - 1);
		i++;
	}
	return result;
}


int ft_atoi_base(char* str, char* base)
{
	int basenum = ft_strlen(base);

	if (!is_base(base) || !is_num(str,basenum))
		return 0x7FFFFFFF;

	int is_positive = True;
	int times_to_multiply = ft_strlen(str);
	int value = 0 ;
	int multiplier = 1;
	int i = times_to_multiply - 1;

	if (*str == '-')
		is_positive = False;

	if (!is_positive || *str == '+')
		times_to_multiply--;

	while(times_to_multiply > 0)
	{
		value = value + ((*(str + times_to_multiply - 1) - '0') * multiplier);
		times_to_multiply--;
		multiplier = multiplier * basenum;
	}

	return value;
}


char *ft_convert_base(char* num, char* base_from, char* base_to)
{
	if (is_base(base_to) || is_base(base_from) || is_num(num,ft_strlen(base_from)))
		return NULL;

	int outputbase = ft_strlen(base_to);
	int num_int = ft_atoi_base(num,base_from);
	int times_to_divide = ft_divisiontimes(num_int, outputbase);
	int modulo_num[32];
	int i = 0;
	int j = 0;
	int max_num = get_max_num(outputbase,times_to_divide);

	char* result = malloc(sizeof(char) + 32);

	if (num_int < 0)
	{
		modulo_num[times_to_divide] = 1;
		num_int = num_int * -1;
	}
	else
		modulo_num[times_to_divide] = 0;

	while(i < times_to_divide)
	{
		modulo_num[i] = num_int % outputbase;
		num_int = num_int / outputbase;
		++i;
	}
	if (modulo_num[times_to_divide] == 1)
		result[0] = "-";

	while (i > 0)
	{
		result[j] = ft_base_char(modulo_num[i - 1] ,outputbase);
		++j;
		--i;
	}
}



/////////////////////////////////exercise 7/////////////////////////////////


int is_in_charset(char chr, char* charset)
{
	int i = 0;

	while(charset[i])
	{
		if (chr == charset[i])
			return True;
	}

	return False;
}

char **ft_split(char* str, char* charset)
{

	if (str[0] || charset[0])
		NULL;

	int i = 0;
	int j = 0;
	int words_amount = 0;
	int k = 0;

	while(str[i])
	{
		if (is_in_charset(str[i],charset))
			++words_amount;

		++i;
	}

	char** result = malloc(words_amount + sizeof(char));
	int* length_of_each_word = malloc(words_amount + sizeof(char));

	i = 0;
	words_amount = 0;

	while(str[i])
	{
		if (is_in_charset(str[i],charset))
		{
			length_of_each_word[words_amount] = j;
			j = 0;
			++words_amount;
		}

		++j;
		++i;
	}

	result[words_amount] = 0;
	i = 1;
	j = 1;
	result[0] = malloc(length_of_each_word[0] + sizeof(char));

	while(str[i])
	{

		if (is_in_charset(str[i],charset))
		{
			result[j] = malloc(length_of_each_word[j]);
			++j;
			k = 0;
		}
		
		else
			result[j][k] = str[i];

		++k;
		++i;
	}

	return result;


}



int main(int argc, char const *argv[])
{
	/* code */
	return 0; 
}