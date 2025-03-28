#include "main.h"
#include <unistd.h>

/**
 * print_string - Affiche une chaîne de caractères
 * @str: La chaîne à afficher
 *
 * Return: Nombre de caractères imprimés
 */
int print_string(char *str)
{
	int i = 0;

	if (str == NULL)
		str = "(null)";

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}

