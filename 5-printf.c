#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/**
 * _printf - prints output according to a format
 * @format: character string containing format specifiers
 *
 * Return: number of characters printed.
 */
int print_hex(char c, int len);
int print_S(char *s);

int _printf_five(const char *format, ...)
{
va_list args;
int i, count = 0;

va_start(args, format);

if (format == NULL)
return (-1);

for (i = 0; format[i] != '\0'; i++)
{
if (format[i] == '%' && format[i + 1] == 'S')
{
i++;
count += print_S(va_arg(args, char *));
}
else
{
count += write(1, &format[i], 1);
}
}

va_end(args);

return (count);
}

/**
 * print_S - prints the string with non-printable characters escaped
 * @s: pointer to string to print
 *
 * Return: number of characters printed
 */
int print_S(char *s)
{
int i, count = 0;

if (s == NULL)
{
count += write(1, "(null)", 6);
return (count);
}

for (i = 0; s[i] != '\0'; i++)
{
if ((s[i] > 0 && s[i] < 32) || s[i] >= 127)
{
count += write(1, "\\x", 2);
count += print_hex(s[i], 2);
}
else
{
count += write(1, &s[i], 1);
}
}

return (count);
}

/**
 * print_hex - prints the hexadecimal representation of a character
 * @c: character to print in hexadecimal
 * @len: length of the hexadecimal representation (0-padded if necessary)
 *
 * Return: number of characters printed
 */
int print_hex(char c, int len)
{
char hex[] = "0123456789ABCDEF";
char buf[3];
int i, count = 0;

buf[2] = '\0';

for (i = len - 1; i >= 0; i--)
{
buf[i] = hex[c % 16];
c /= 16;
}

count += write(1, buf, len);

return (count);
}
