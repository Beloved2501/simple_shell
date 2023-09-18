#include "general.h"
#include "text.h"

/**
 * digits - this funct Counts the no. of digits of a no.
 *
 * @n: this is the Number.
 *
 * Return: the function returns Digits.
 **/
int digits(int n)
{
	int i;

	for (i = 0; n != 0; i++, n /= 10)
		;

	return (i);
}

/**
 * to_string - Converts the  @number to str.
 *
 * @number: the No. to convert
 *
 * Return: the funct returns the Number as string
 **/
char *to_string(int number)
{
	int n_digits, i;
	char *_number;

	n_digits = digits(number);
	_number = malloc(n_digits * sizeof(char) + 2);
	if (number == 0)
	{
		_number[0] = '0';
		_number[1] = '\0';
		return (_number);
	}
	/* Check NULL */

	_number[n_digits] = '\0';
	for (i = n_digits - 1; number != 0; number /= 10, i--)
		_number[i] = (number % 10) + '0';

	return (_number);
}


/**
 * is_numerical - the funct to Check if is a digit.
 *
 * @n: this is the Number
 *
 * Return: returns If is a number, return 1 else return 0
 */
int is_numerical(unsigned int n)
{
	return (n >= '0' && n <= '9');
}

/**
 * _atoi - Converts  a string to a number.,
 *
 * @s: String to be converted.
 *
 * Return: Returns the number.
 */
int _atoi(char *s)
{
	unsigned int number, i;
	int sign;

	sign = 1;
	number = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (is_numerical(s[i]))
		{
			number = (s[i] - 48)	+ number * 10;

			if (s[i + 1] == ' ')
				break;
		}
		else if (s[i] == '-')
		{
			sign *= -1;
		}

	}

	return (number * sign);
}

/**
 * contains_letter - the funct Searches non-digits in a string.,
 *
 * @s: String for search.
 *
 * Return: If a non-digits was found, return _TRUE
 * if not, return _FALSE
 **/
int contains_letter(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (is_numerical(s[i]) == _FALSE)
			return (_TRUE);
	}

	return (_FALSE);
}
