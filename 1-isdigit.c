#include "monty.h"
/**
 *_isdigit - checks for a digit (0 through 9).
 *@c: value to be validate.
 *Return: int.
 */
int _isdigit(char *c)
{
	int i;
	int cont = 0;

	if (c == NULL)
	{
		return (0);
	}
	for (i = 0 ; *(c + i) != '\0' ; i++)
	{
		if (cont == 2)
		{
			return (0);
		}
		if ((c[i] >= '0' && c[i] <= '9') ||
(c[i] == '-' && (c[i + 1] >= '0' && c[i + 1] <= '9')))
		{
			if (c[i] == '-' && (c[i + 1] >= '0' && c[i + 1] <= '9'))
			{
				cont++;
			}
		}
		else
		{
			return (0);
		}
	}
	return (1);
}
