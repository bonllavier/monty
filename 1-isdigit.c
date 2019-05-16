#include "monty.h"
/**
 *_isdigit - checks for a digit (0 through 9).
 *@c: value to be validate.
 *Return: int.
 */
int _isdigit(char *c)
{
        int i;
	if(c == NULL)
	{
		return (0);
	}
	for(i = 0 ; *(c + i) != '\0' ; i++)
	{
		if (c[i] >= '0' && c[i] <= '9')
		{
		}
		else
		{
			return (0);
		}
	}
	return (1);
}
