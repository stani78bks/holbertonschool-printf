#include <stdarg.h>
#include "main.h"
#include <stddef.h>

/**
 * _printf - Custom implementation of printf
 * @format: Format string containing format specifiers
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	if (format == NULL)
		return (-1);

	if (format[0] == '%' && format[1] == '\0')
		return (-1);


	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (-1);
			else if (*format == 'c')
				count += _putchar(va_arg(args, int));
			else if (*format == 's')
				count += print_string(va_arg(args, char*));
			else if (*format == '%')
				count += _putchar('%');
			else
			{
				count += _putchar('%');
				count += _putchar(*format);
			}
		}
		else
			count += _putchar(*format);
		format++;
	}

	va_end(args);
	return (count);
}

