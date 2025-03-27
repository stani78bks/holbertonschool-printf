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
 * @str: La chaîne de caractères à afficher
 * Return: Le nombre de caractères affichés
 */
int print_string(char *str)
{
	int count = 0;

	if (str == NULL)
		str = "(null)";
	while (*str)
	{
		putchar(*str);
		str++;
		count++;
	}
	return (count);
}

/**
 * handle_format - Gère les formats spécifiques (%c, %s, %%)
 * @format: Le format à traiter
 * @args: La liste d'arguments variable
 * Return: Le nombre de caractères affichés
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
 * _printf - Fonction personnalisée qui imite printf
 * @format: La chaîne de format
 * Return: Le nombre de caractères imprimés, ou -1 en cas d'erreur
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

