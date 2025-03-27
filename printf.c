#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Fonction qui imite printf
 * @format: Chaîne de format avec des spécificateurs
 * Return: Nombre de caractères imprimés
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	if (!format)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format == '%' && (*(++format) == 'd' || *format == 'i'))
			count += print_int(va_arg(args, int));
		else
			count += write(1, format, 1);
		format++;
	}

	va_end(args);
	return (count);
}

