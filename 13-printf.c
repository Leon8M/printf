#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * print_rev - Prints a string in reverse
 * @s: Pointer to string to print in reverse.
 *
 * Return: The length of the printed string
 */
int print_rev(char *s)
{
int len = 0;
int i;

while (s[len] != '\0')
len++;

for (i = len - 1; i >= 0; i--)
write(1, &s[i], 1);

return (len);
}

/**
 * _printf - Prints a formatted string to standard output
 * @format: Pointer to format string
 *
 * Return: The number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf_thirteenth(const char *format, ...)
{
va_list args;
int printed = 0;

va_start(args, format);

while (*format)
{
if (*format == '%')
{
format++;

if (*format == 'r')
printed += print_rev(va_arg(args, char *));
}
else
{
write(1, format, 1);
printed++;
}

format++;
}

va_end(args);

return (printed);
}
