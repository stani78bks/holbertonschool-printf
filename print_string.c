#include <stdarg.h>
#include <unistd.h>

int print_string(va_list args)
{
    char *str = va_arg(args, char *);
    int count = 0;

    if (str == NULL)
        str = "(null)";

while (*str != '\0')
    {
        write(1, str, 1);
        str++;
        count++;
    }

    return count;
}
