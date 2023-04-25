#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

/**
 * _printf - prints output according to a format
 * @format: character string containing format specifiers
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
va_list args;
int i, count = 0;

va_start(args, format);

if (format == NULL)
return (-1);

for (i = 0; format[i] != '\0'; i++)
{
if (format[i] == '%')
{
i++;

if (format[i] == 'c')
{
char c = (char) va_arg(args, int);
count += write(1, &c, 1);
}
else if (format[i] == 's')
{
char *str = va_arg(args, char *);
count += write(1, str, strlen(str));
}
else if (format[i] == '%')
{
count += write(1, "%", 1);
}
else
{
count += write(1, "%", 1);
count += write(1, &format[i], 1);
}
}
else
{
count += write(1, &format[i], 1);
}
}

va_end(args);

return (count);
}
