#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Fonction personnalisée qui imite printf
 * @format: chaîne de format
 * Return: nombre de caractères imprimés, ou -1 en cas d'erreur
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
        if (*format == '%')  /* Détection d'un caractère '%' */
        {
            format++;  /* Passer au caractère suivant */

            if (*format == 'c')  /* %c : caractère */
            {
                char c = va_arg(args, int);
                write(1, &c, 1);
                count++;
            }
            else if (*format == 's')  /* %s : chaîne de caractères */
            {
                char *str = va_arg(args, char *);

                if (str == NULL)  /* Si la chaîne est NULL, afficher "(null)" */
                    str = "(null)";

                while (*str)  /* Afficher chaque caractère de la chaîne */
                {
                    write(1, str, 1);
                    str++;
                    count++;
                }
            }
            else if (*format == '%')  /* %% : afficher '%' */
            {
                write(1, "%", 1);
                count++;
            }
            else  /* Si c'est un format inconnu */
            {
                write(1, "%", 1);  /* Afficher le '%' */
                write(1, format, 1);  /* Afficher le caractère suivant */
                count += 2;  /* Ajouter 2 à count (le '%' et le caractère suivant) */
            }
        }
        else  /* Caractère normal */
        {
            write(1, format, 1);
            count++;
        }
        format++;  /* Passer au caractère suivant */
    }

    va_end(args);
    return (count);
}

