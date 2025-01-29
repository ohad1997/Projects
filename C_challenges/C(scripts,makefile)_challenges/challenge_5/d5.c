#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>

#define True 1;
#define False 0;


void ft_putchar(char c)
{
    write(0,&c,1);
}

void ft_putstr(char* str)
{
	int i = 0;

	while(str[i] != '\0')
	{
		write(0,(str + i),1);
		i++;
	}
}



void ft_putnum(int num)
{
	int size = 1;
	int num2 = num;
	int num3 = num;

	while(num2 > 10)
	{
		num2 = num2 / 10;
		size = size * 10;
	}

	while(num3 > 0)
	{
		char c = (char) (num3 / size) + 48;
		num3 = num3 % size;
		size = size / 10;
		ft_putchar(c);
	}
}



int ft_atoi_check(char* str)
{
 int is_equal1 = (int) *str - 48 > -1;
 int is_equal2 = (int) *str - 48 < 10;
 int is_equal3 = *str == '-';
 int is_equal4 = *str == '+';
 int index = 0;

 while(str[index] != '\0')
 {
 	if (is_equal1 || is_equal2 || is_equal3 || is_equal4)
 		return 1;
 	index++;
 }
 	
 return 0;
}

int ft_atoi (char* str)
{
	if (!ft_atoi_check(str))
		return 0;

	int is_positive = 1;
	int size = 0;
	int value = 0;
	int i = 0;

	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			is_positive = 0;
		str++;
	}

	while(str[size] != '\0')
		size++;
	
	while(i < size)
	{
		int temp = (int) str[i] - 48;
		value = (value * 10) + temp;
		i++;
	}

	if (!is_positive)
		value = 0 - value;
	return value;
}



char* ft_strcpy(char* desc, char* src)
{
	int size = 0;
	int i = 0;

	while(src[size] != '\0')
		size++;

	char *cpy = malloc(size + sizeof(char));
	if (cpy == NULL)
		return NULL;
	while(i < size)
	{
		cpy[i] = src[i];
		i++; 
	}

	desc = cpy;

	return desc;

}



char* ft_strncpy(char* desc, char* src, int numOfChars)
{
	int size = 0;

	while(src[size] != '\0')
		size++;

	char* cpy = malloc(numOfChars + sizeof(char));
	if (cpy == NULL)
		return NULL;
	size = 0;

	while(size < numOfChars)
	{
		cpy[size] = src[size];
		size++; 
	}

	desc = cpy;

	return desc;

}



char* ft_strstr(char* str, char* to_find)
{
	int i = 0;
	int j = 0;
	int size = 0;

	while(str[size] != '\0')
		size++;

	char* cpy = malloc(size + sizeof(char));

	if(cpy == NULL)
		return NULL;

	while(str[i] != '\0')
	{
		if (str[i] == to_find[j])
		{
			cpy[j] = str[i];
			j++;
		}
		else
			j =0;

		i++;
	}

	i = 0;
	j = 0;
	while(cpy[i] != '\0')
		i++;

	while(to_find[j] != '\0')
		j++;

	if (j != i)
		return NULL;

	return cpy;
}




int ft_strcmp(char* str1, char* str2)
{
	int value1 = 0;
	int value2 = 0;
	int i = 0;

	int str1_end = 0;
	int str2_end = 0;

	while(str2_end == 0 || str1_end == 0)
	{
		if (str1[i] == '\0')
			str1_end = 1;
		if (str2[i] == '\0')
			str2_end = 1;

		if (str1_end == 0)
			value1 = value1 + (int) str1[i];

		if (str2_end == 0)
			value2 = value2 + (int) str2[i];

		i++;
	}

	if (value1 > value2)
		return -1;

	if (value1 < value2)
		return 1;

	if (value1 == value2)
		return 0;

	return 214800000;
}




int ft_strncmp(char* str1, char* str2, int numOfChars)
{
	int value1 = 0;
	int value2 = 0;
	int i = 0;

	int str1_end = 0;
	int str2_end = 0;

	while((str2_end == 0 || str1_end == 0) && i < numOfChars)
	{
		if (str1[i] == '\0')
			str1_end = 1;
		if (str2[i] == '\0')
			str2_end = 1;

		if (str1_end == 0)
			value1 = value1 + (int) str1[i];

		if (str2_end == 0)
			value2 = value2 + (int) str2[i];

		i++;
	}

	if (value1 > value2)
		return -1;

	if (value1 < value2)
		return 1;

	if (value1 == value2)
		return 0;

	return 214800000;
}



char* ft_strupcase(char* str)
{
	int i = 0;
	int size = 0;

	while(str[size] != '\0')
		size++;

	char* cpy = malloc(size + sizeof(char));

	while(str[i] != '\0')
	{
		if ((int)str[i] > 96 && (int) str[i] < 123)
			cpy[i] = (char)(str[i] - 32);

		else
			cpy[i] = str[i];

		i++;
	}

	str = cpy;
	return str;
}




char* ft_strlowcase(char* str)
{
	int i = 0;
	int size = 0;

	while(str[size] != '\0')
		size++;

	char* cpy = malloc(size + sizeof(char));

	while(str[i] != '\0')
	{
		if ((int)str[i] > 64 && (int) str[i] < 91)
			cpy[i] = (char)(str[i] + 32);

		else
			cpy[i] = str[i];

		i++;
	}

	str = cpy;
	return str;
}





char* ft_strcapitelizee(char* str)
{
	int i = 0;
	int size = 0;

	while(str[size] != '\0')
		size++;

	char* cpy = malloc(size + sizeof(char));

	while(str[i] != '\0')
	{

		if ((int)str[i] > 64 && (int) str[i] < 91)
			cpy[i] = (char)(str[i] + 32);

		else if ((int)str[i] > 96 && (int) str[i] < 123 && ((int)*(str + i - 1) < 65|| (int) *(str + i - 1) > 122 || ((int)str[i] > 90 && (int) str[i] < 97)))
			cpy[i] = (char)(str[i] - 32);

		else
			cpy[i] = str[i];

		i++;
	}

	str = cpy;
	return str;
}




int ft_alpha(char* str)
{
	int i = 0;

	while(str[i] != '\0')
	{
		if (((int)str[i] < 65 && (int) str[i] < 122) || ((int)str[i] > 91 && (int) str[i] < 96))
			return 0;
		i++;
	}

	return 1;
}



int ft_numeric(char* str)
{
	int i = 0;

	while(str[i] != '\0')
	{
		if ((int)str[i] < 48 || (int) str[i] > 57)
			return 0;
		i++;
	}

	return 1;
}




int ft_lowercase(char* str)
{
	int i = 0;

	while(str[i] != '\0')
	{
		if ((int)str[i] < 97 || (int) str[i] > 122)
			return 0;
		i++;
	}

	return 1;
}




int ft_uppercase(char* str)
{
	int i = 0;

	while(str[i] != '\0')
	{
		if ((int)str[i] < 65 || (int) str[i] > 90)
			return 0;
		i++;
	}

	return 1;
}




int ft_printable(char* str)
{
	int i = 0;

	while(str[i] != '\0')
	{
		if ((int)str[i] < 32 || (int) str[i] > 126)
			return 0;
		i++;
	}

	return 1;
}




char* ft_strcat(char* dest, char* src )
{
	int size_dest = 0;
	int size_src = 0;
	int i = 0;
	int j = 0;
	int k = 0;

	while(dest[size_dest] != '\0')
		size_dest++;
	while(src[size_src] != '\0')
		size_src++;

	char* cpy = malloc(size_dest + size_src + sizeof(char));
	if (cpy == NULL)
		return NULL;

	while((k) < (size_dest + size_src))
	{
		if(i < size_dest)
		{
			cpy[k] = dest[i];
			i++;
		}
		else
		{
			cpy[k] = src[j];
			j++;
		}
		k = i + j;;
	}

	return cpy;
}







char* ft_strncat(char* dest, char* src ,int num)
{
	if (num < 0)
		return NULL;
	
	int size_dest = 0;
	int size_src = 0;
	int i = 0;
	int j = 0;
	int k = 0;

	while(dest[size_dest] != '\0')
		size_dest++;
	while(src[size_src] != '\0')
		size_src++;

	if (num > size_dest)
		return NULL;

	char* cpy = malloc(size_dest + num + sizeof(char));
	if (cpy == NULL)
		return NULL;

	while((k) < (size_dest + num))
	{
		if(i < size_dest)
		{
			cpy[k] = dest[i];
			i++;
		}
		else
		{
			cpy[k] = src[j];
			j++;
		}
		k = i + j;;
	}

	return cpy;
}




int ft_strlen(char* arr)
{
	int result = 0;

	if (arr != NULL)
	{
		while(arr[result] != '\0')
			result++;
	}
	else
		return (-1);

	return (result);
}


int ft_strlcat(char* dest, char* src ,int length)
{
	if (length < 0 || *src == '\0')
		return -1;

	int size_dest = strlen(dest);
	int size_src  = strlen(src);
	int i         = size_dest;

	if (length > size_src + size_dest)
		return -1;

	while(i < length)
	{
		if (length < size_dest)
			*(dest + length + 1) = (char) '\0';

		else
			dest[i] = *(src + i - size_dest);

		i++;
	} 
	dest[i] = (char) '\0';

	return (size_dest + size_src);
}






int ft_strlcpy(char* dest, char* src ,int length)
{
	if (length < 0 || *src == '\0')
		return -1;

	int size_dest = strlen(dest);
	int size_src  = strlen(src);
	int i         = 0;

	if (length > size_src)
		return -1;

	while(i < length)
	{
		dest[i] = src[i];
		i++;
	} 

	dest[i] = (char) '\0';

	return (size_src);
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

int is_base(char* base)
{
	int i = 0;
	int size = ft_strlen(base);


	while(i < size)
	{
		if (i < 10 && base[i] != (char)(i + 48))
			return 0;

		else if (i > 9 && base[i] != (char) (i + 55))
			return 0;
		i++;
	}

	return 1;
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


void ft_putnbr_base(int num ,char* base)
{
	if (!is_base(base))
		return;

	int basenum = ft_strlen(base);
	int times_to_divide = ft_divisiontimes(num, basenum);
	int modulo_num[32];
	int i = 0;
	int max_num = get_max_num(basenum,times_to_divide);

	if (num < 0)
	{
		modulo_num[times_to_divide] = 1;
		num = num * -1;
	}
	else
		modulo_num[times_to_divide] = 0;

	while(i < times_to_divide)
	{
		modulo_num[i] = num % basenum;
		num = num / basenum;
		i++;
	}

	if (modulo_num[times_to_divide] == 1)
		ft_putchar('-');

	while (i > 0)
	{
		ft_putchar(ft_base_char(modulo_num[i - 1] ,basenum));
		i--;
	}
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



void ft_putstring_non_printable(char* str)
{
	int i = 0;
	int size = ft_strlen(str);

	while(i < size)
	{
		if (str[i] < 10)
		{
			ft_putchar('\\');
			ft_putchar((char) (str[i]) + '0') ;
		}
		else if (str[i] < 17)
		{
			ft_putchar('\\');
			ft_putchar((char) (str[i]) + 'a' - 10) ;
		}
		else
			ft_putchar(str[i]);

		i++;
	}
}




void ft_print_hexint(int num)
{
	int length_in_hex = ft_divisiontimes(num, 16);

	while(8 - length_in_hex > 0)
	{
		ft_putchar('0');
		length_in_hex++;
	}

	ft_putnbr_base(num,"0123456789ABCDEF");
}

void ft_print_hexchar(unsigned char c)
{
	if (ft_divisiontimes(c, 16) == 1)
		ft_putchar('0');

	ft_putnbr_base(c,"0123456789ABCDEF");
}

void* ft_print_memory(void* addr, unsigned int size)
{
	unsigned char * ptr = addr;
	int i = 0;
	int j = 0;
	int line_num = 0;

	while (i < size)
	{
		if (i % 16 == 0)
		{
		
			ft_print_hexint(line_num);
			ft_putchar(':');
			ft_putchar(' ');
			ft_putchar(' ');
			j = 0;
			while(j < 16 && j + i < size)
			{
				if (j % 2 == 0)
				ft_putchar(' ');

				ft_print_hexchar(ptr[i + j]);
				j++;
			}
			ft_putchar(' ');
		}


		if (ptr[i] <= 31 || ptr[i] >= 127)
			ft_putchar('.');
		else 
			ft_putchar(ptr[i]);

		
		if (i% 16 == 15)
		{
			ft_putchar('\n');
		}
		

		i++;
		j = 0;

		line_num ++;
	}

	return addr;
}


























int main(int argc, char const *argv[])
{
	char* str =
"\n""Skip to main content"
"\n""Accessibility help"
"\n""Accessibility feedback"
"\n""Seasonal Holidays 2022"
"\n""Camera search"
"\n""All"
"\n""Images"
"\n""Books"
"\n""News"
"\n""Shopping"
"\n""More"
"\n""Tools"
"\n"""
"\n""About 98,700,000 results (0.63 seconds) "
"\n""Non-Printable characters include all escape characters such as '\n', \t', '\r', '\x16', '\\xlf', and so on."
"\n"""
"\n""Why do we use Python String isprintable()? - Toppr"
"\n""https://www.toppr.com › methods-and-functions › methods"
"\n""About featured snippets"
"\n""•"
"\n""Feedback\0\0\0\0\0"
"\n"""
"\n""Stripping non printable characters from a string in python"
"\n""https://stackoverflow.com › questions › stripping-non-p..."
"\n""Nov 19, 2011 — Nonprintable characters are those characters defined in the Unicode character database as “Other” or “Separator”, excepting the ASCII space (0x20) which is ..."
"\n""16 answers"
"\n""  ·  Top answer: Iterating over strings is unfortunately rather slow in Python. Regular expressions are over ..."
"\n""Show non printable characters in a string - python"
"\n""Dec 18, 2012"
"\n""python - How to remove non-printable characters from string?"
"\n""Dec 16, 2019"
"\n""Check if a String List contains non-printable characters"
"\n""Jul 6, 2020"
"\n""print non-printable characters in a given string? - Stack Overflow"
"\n""Jun 21, 2012"
"\n""More results from stackoverflow.com"
"\n""People also ask"
"\n""Which characters are non printable?"
"\n""How do I find non printable characters?"
"\n""How do I delete all non printable characters?"
"\n""How do you check whether all the characters in a string is printable?"
"\n""Where are non-printing characters word?"
"\n""What is an example of a printable character?"
"\n""Feedback"
"\n"""
"\n""Python string.isprintable() Method (With Examples)"
"\n""https://www.tutorialsteacher.com › python › string-ispri..."
"\n""Non-printable characters are characters that are not visible and do not occupy a space in printing. Some characters in the Unicode character database as \"Other\" ..."
"\n"""
"\n""Reference Non Printable Characters List - Fjolt"
"\n""https://fjolt.com › article › linux-non-printable-characters"
"\n""Name	Binary	Decimal	Hexadecimal	Octal	Caret Notation	Escape Seq..."
"\n""Null	000 0000	0	00	000	^@	\0"
"\n""Start of Heading (SOH)	000 0001	1	01	001	^A	"
"\n""Start of Text (STX)	000 0010	2	02	002	^B	"
"\n""View 30 more rows"
"\n"""
"\n""Python String isprintable() Method - Learn By Example"
"\n""https://www.learnbyexample.org › python-string-isprint..."
"\n""The isprintable() method returns TRUE if the string is empty or all characters in it are printable. It returns FALSE if the string contains at least one non- ..."
"\n"""
"\n""REFERENCE: Full List of Non Printable Characters"
"\n""https://dev.to › smpnjn › full-list-of-non-printable-char..."
"\n""Mar 14, 2022 — Below, find a list of all non printable characters, along with their binary, decimal and hexadecimal codes. You can also find their escape ..."
"\n""Missing: string ‎| Must include: string"
"\n"""
"\n""Non-printable ASCII characters list - Aticleworld"
"\n""https://aticleworld.com › Blog Post"
"\n""7 · 8 · 9 ; 7 · 8 · 9 ; BEEP (BEL) · BACKSPACE (BS) · HORIZONTAL TAB (HT) ..."
"\n"""
"\n""Printable Characters Python With Code Examples"
"\n""https://www.folkstalk.com › tech › printable-characters-..."
"\n""Non-printable characters are characters that are not visible and do not occupy a space in printing. Some characters in the Unicode character database as \"Other\" ..."
"\n"""
"\n""Python String isprintable() Method - GeeksforGeeks"
"\n""https://www.geeksforgeeks.org › python-string-isprinta..."
"\n""Aug 12, 2021 — True – If all characters in the string are printable or the string is empty. False – If the string contains 1 or more nonprintable characters."
"\n"""
"\n""NON PRINTABLE CHARACTERS"
"\n""https://web.itu.edu.tr › courses › mikroisl › ascii"
"\n""1, 1, START OF HEADING (SOH), 17, 11 ..."
"\n""People also ask"
"\n""What are the non-printable characters in Excel?"
"\n""What are the non-printable ASCII characters called?"
"\n""What is non-printable characters in Python?"
"\n""How many non-printable ASCII characters are there?"
"\n""Feedback"
"\n""Related searches"
"\n""non printable characters"
"\n""non printable unicode characters"
"\n""list of non printable characters in excel"
"\n""ascii non printable characters"
"\n""python non printable characters"
"\n""invalid non-printable character u+200b"
"\n""python remove non printable characters"
"\n""syntaxerror: invalid non-printable character u+00a0"
"\n""	1	"
"\n""2"
"\n""	"
"\n""3"
"\n""	"
"\n""4"
"\n""	"
"\n""5"
"\n""	"
"\n""6"
"\n""	"
"\n""7"
"\n""	"
"\n""8"
"\n""	"
"\n""9"
"\n""	"
"\n""10"
"\n""	"
"\n""Next"
"\n""France"
"\n""Prasville"
"\n"" - Based on your past activity"
"\n"" - Update location"
"\n""HelpSend feedbackPrivacyTermsConsumer informationReport inappropriate content"
;



	ft_print_memory(str,4096);
	return 0;

	// printf("NULL");
}
