#include <unistd.h>

/**
 * print_char - Affiche un caractère
 * @c: Caractère à afficher
 *
 * Return: 1 (Nombre de caractères imprimés)
 */
int print_char(char c)
{
    return (write(1, &c, 1));
}

