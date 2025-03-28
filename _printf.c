#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Fonction qui imite printf
 * @format: Chaîne de format
 * Return: Nombre total de caractères imprimés
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
        if (*format == '%')
        {
            format++;
            if (*format == 'c')
                count += print_char(va_arg(args, int));
            else if (*format == 's')
                count += print_string(va_arg(args, char *));
            else if (*format == '%')
                count += print_char('%');
            else
                count += print_char('%'), count += print_char(*format);
        }
        else
        {
            count += print_char(*format);
        }
        format++;
    }

    va_end(args);
    return (count);
}

