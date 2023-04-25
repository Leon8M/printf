#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * print_interger - Prints an integer using recursion.
 * @n: The integer to print.
 * @sign: A flag indicating if the number is negative.
 *
 * Return: The number of digits printed.
 */
int print_interger(int n, int sign)
{
int digits = 0;

if (n < 0)
{
n = -n;
sign = 1;
}

if (n / 10)
digits += print_interger(n / 10, sign);

digits += write(STDOUT_FILENO, &"0123456789"[n % 10], 1);

return (digits + sign);
}

/**
 * _printf - Prints a formatted string to standard output.
 * @format: A pointer to a string containing the format specifier.
 * ...: The optional arguments to format.
 *
 * Return: The number of characters printed.
 */
int _printf_seven(const char *format, ...)
{
va_list args;
int i, j, sign, printed = 0;

va_start(args, format);

for (i = 0; format && format[i]; i++)
{
if (format[i] != '%')
{
write(STDOUT_FILENO, &format[i], 1);
printed++;
continue;
}

sign = 0;
i++;

while (format[i] == ' ' || format[i] == '+' || format[i] == '#')
{
if (format[i] == ' ')
sign = (sign == 0) ? -1 : sign;

if (format[i] == '+')
sign = 1;

if (format[i] == '#')
write(STDOUT_FILENO, "0", 1);

i++;
}

if (format[i] == 'd' || format[i] == 'i')
{
int n = va_arg(args, int);
printed += print_interger(n, (n < 0 || sign == 1) ? 1 : 0);
}
else if (format[i] == 's')
{
char *s = va_arg(args, char *);
if (!s)
s = "(null)";
j = 0;
while (s[j])
j++;
printed += write(STDOUT_FILENO, s, j);
}
else if (format[i] == 'c')
{
char c = va_arg(args, int);
printed += write(STDOUT_FILENO, &c, 1);
}
}

va_end(args);

return (printed);
}
