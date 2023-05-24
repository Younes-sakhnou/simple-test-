#include "shellix.h"

int _isdigit(char *str);
void reverse_string(char *str, int length);
char *int_to_str(int num);

/**
 * _atoi -  a function that convert a string to an integer.
 * @s: the given string.
 * Return: an integer value.
 */
int _atoi(char *s)
{
	int i, sign, n, factor;
	unsigned int num;

	sign = 1;
	num = 0;
	for (i = 0; *(s + i) != '\0'; i++)
	{
		if (*(s + i) == '-')
			sign *= -1;
		else if (*(s + i) >= '0' && *(s + i) <= '9')
		{
			factor = 1;
			n = i + 1;
			while (*(s + n) >= '0' && *(s + n) <= '9')
			{
				factor *= 10;
				n++;
			}
			num += (*(s + i) - '0') * factor;
			if (!(*(s + i + 1) >= '0' && *(s + i + 1) <= '9'))
				break;
		}
		else
			continue;
	}
	return (num * sign);
}

/**
 * string_rev - a function that reverse a string
 * @str: the given string
 * @length: the length of the string
 *
 * Return: void.
 */
void string_rev(char *str, int length)
{
	char temp;
	int end, start = 0;

	end = length - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

/**
 * int_to_str - a function converts a interger to a string
 * @num: the given integer
 *
 * Return: a pointer to the string.
 */
char *int_to_str(int num)
{
	char *str;
	int is_negative, length, digit, index, temp;

	if (num == 0)
	{
		str = (char *) malloc(2 * sizeof(char));
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	is_negative = 0;
	length = 0;
	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}
	temp = num;
	while (temp > 0)
	{
		temp = temp / 10;
		length++;
	}
	if (is_negative)
	{
		length++;
	}
	str = (char *) malloc((length + 1) * sizeof(char));
	index = 0;
	while (num > 0)
	{
		digit = num % 10;
		str[index++] = digit + '0';
		num = num / 10;
	}
	if (is_negative)
	{
		str[index++] = '-';
	}
	str[index] = '\0';
	string_rev(str, index);
	return (str);
}

/**
 * _isdigit - checks for digits.
 * @str: the int to check if it's a digit.
 *
 * Return: 1 is a digit and 0 otherwise
 */
int _isdigit(char *str)
{
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}
