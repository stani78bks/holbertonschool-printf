#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_char - Affiche un caractère
 * @c: Le caractère à afficher
 * Return: 1 (le nombre de caractères affichés)
 */
int print_char(char c)
{
	putchar(c);
	return (1);
}

/**
 * print_string - Affiche une chaîne de caractères
 * @str: La chaîne à afficher
 * Return: Nombre de caractères affichés
 */
int print_string(char *str)
{
	int count = 0;

	if (str == NULL)
		str = "(null)";
	while (*str)
	{
		putchar(*str);
		count++;
		str++;
	}
	return (count);
}

/**
 * handle_format - Gère les spécificateurs de format
 * @format: Le caractère de format
 * @args: Liste d'arguments
 * Return: Nombre de caractères affichés
 */
int handle_format(char format, va_list args)
{
	if (format == 'c')
		return (print_char(va_arg(args, int)));
	if (format == 's')
		return (print_string(va_arg(args, char *)));
	if (format == '%')
		return (print_char('%'));

	putchar('%');
	putchar(format);
	return (2);
}

/**
 * _printf - Imite la fonction printf
 * @format: Chaîne de format
 * Return: Nombre de caractères imprimés
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format)
				count += handle_format(*format, args);
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}

