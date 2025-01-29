#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0




////////////////////////////////exercise 0////////////////////////////////


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



int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}