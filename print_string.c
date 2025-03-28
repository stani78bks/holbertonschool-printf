#include <stdarg.h>
#include <unistd.h>
/**
 * print_string - Fonction qui imprime une chaîne de caractères.
 * @args: Liste d'arguments qui contient la chaîne à afficher.
 * Retourne le nombre de caractères imprimés.
 */
int print_string(va_list args)
{
    char *str = va_arg(args, char*);
    int i = 0;
    // Si la chaîne est NULL, afficher "(null)".
    if (str == NULL)
        str = "(null)";
    // Afficher chaque caractère de la chaîne.
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
    return i;
}
