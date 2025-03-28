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
    return (write(1, &c, 1) == -1 ? -1 : 1);
}

/**
 * print_string - Affiche une chaîne de caractères
 * @args: Liste d'arguments
 * Return: Nombre de caractères imprimés
 */
int print_string(va_list args)
{
    char *str = va_arg(args, char *);
    int count = 0, i;

    if (!str)
        str = "(null)";
    
    for (i = 0; str[i] != '\0'; i++)
    {
        if (write(1, &str[i], 1) == -1)
            return (-1);
        count++;
    }
    return (count);
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
            if (*format == 'c')
                temp = print_char(args);
            else if (*format == 's')
                temp = print_string(args);
            else if (*format == '%')
                temp = write(1, "%", 1);
            else
            {
                temp = write(1, "%", 1) + write(1, format, 1);
            }

            if (temp == -1)
                return (-1);
            count += temp;
        }
        else
        {
            if (write(1, format, 1) == -1)
                return (-1);
            count++;
        }
        format++;
    }

    va_end(args);
    return (count);
}

