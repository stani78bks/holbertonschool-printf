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
        if (*format == '%')  /* Détecte un formatage */
        {
            format++; /* Passe au caractère suivant */

            if (*format == 'c')  /* Gestion du %c */
            {
                char c = va_arg(args, int);
                write(1, &c, 1);
                count++;
            }
            else if (*format == 's') /* Gestion du %s */
            {
                char *str = va_arg(args, char *);
                if (!str)
                    str = "(null)"; /* Pour éviter les erreurs avec NULL */
                while (*str)
                {
                    write(1, str, 1);
                    str++;
                    count++;
                }
            }
            else if (*format == '%') /* Gestion de %% */
            {
                write(1, "%", 1);
                count++;
            }
            else /* Gestion des formats inconnus (%X, %!) */
            {
                write(1, "%", 1);
                write(1, format, 1);
                count += 2;
            }
        }
        else /* Caractère normal */
        {
            write(1, format, 1);
            count++;
        }
        format++;
    }

    va_end(args);
    return (count);
}

