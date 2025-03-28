#include <stdarg.h>
#include <unistd.h>

/**
 * print_char - Affiche un caractère
 * @args: Liste d'arguments
 * Return: 1 (nombre de caractères imprimés)
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (write(1, &c, 1));
}

/**
 * print_string - Affiche une chaîne de caractères
 * @args: Liste d'arguments
 * Return: Nombre de caractères imprimés
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;

	/* Ajout d'une ligne vide après les déclarations */
	if (!str)
		str = "(null)";

	while (*str)
	{
		if (write(1, str, 1) == -1)
			return (-1);
		str++;
		count++;
	}

	return (count);
}

/**
 * handle_format - Gère les spécificateurs de format
 * @format: Caractère de format
 * @args: Liste d'arguments
 * Return: Nombre de caractères imprimés
 */
int handle_format(char format, va_list args)
{
	if (format == 'c')
		return (print_char(args));

	if (format == 's')
		return (print_string(args));

	if (format == '%')
		return (write(1, "%", 1));

	/* Supprime le else inutile */
	write(1, "%", 1);
	write(1, &format, 1);
	return (2);
}

/**
 * _printf - Implémentation simplifiée de printf
 * @format: Chaîne de format
 * Return: Nombre de caractères imprimés
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0, temp;

	if (!format)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			temp = handle_format(*format, args);
		}
		else
		{
			temp = write(1, format, 1);
		}

		if (temp == -1)
		{
			va_end(args);
			return (-1);
		}
		count += temp;
		format++;
	}

	va_end(args);
	return (count);
}

