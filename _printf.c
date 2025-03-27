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

            /* Si c'est un format valide */
            if (*format == 'c')  /* %c */
            {
                char c = va_arg(args, int);
                write(1, &c, 1);
                count++;
            }
            else if (*format == 's') /* %s */
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
            else if (*format == '%') /* %% */
            {
                write(1, "%", 1);
                count++;
            }
            else /* Pour les formats inconnus (%X, %!, etc.) */
            {
                /* Affiche le caractère '%' et le caractère suivant */
                write(1, "%", 1);  /* Affiche '%' */
                write(1, format, 1); /* Affiche le caractère suivant */
                count += 2;  /* Compte le '%' et le caractère suivant */
            }
        }
        else /* Si ce n'est pas un % (caractère normal) */
        {
            write(1, format, 1);
            count++;
        }
        format++;  /* Passe au caractère suivant */
    }

    va_end(args);
    return (count);
}

