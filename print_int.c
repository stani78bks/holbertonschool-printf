#include "main.h"
#include <unistd.h>

/**
 * print_int - Affiche un entier en gérant les nombres négatifs
 * @n: Nombre entier à afficher
 * Return: Nombre de caractères affichés
 */
int print_int(int n)
{
	int count = 0;
	char buffer[12];
	int i = 0;
	unsigned int num;

	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		num = -n;
	}
	else
	{
		num = n;
	}

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	while (num > 0)
	{
		buffer[i++] = (num % 10) + '0';
		num /= 10;
	}

	while (i--)
	{
		write(1, &buffer[i], 1);
		count++;
	}

	return (count);
}

