#include "main.h"
/**
 * print_alphabet - prints what the function inside it does
 * print_alphabet - prints alphabet in lowercase
 * Return: zero (0)
 */
void print_alphabet(void)
{
	char i = 'a';

	while (i <= 'z')
	{
		_putchar(i);
		i++;
	}
	_putchar('\n');
}

