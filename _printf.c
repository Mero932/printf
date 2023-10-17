#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * _printf - produces output according to a format.
 * @format: character string.
 *
 * Return: count (character of strings)
 */
int _printf(const char *format, ...)
{
int i, j, count;
char *str;
i = 0;
j = 0;
count = 0;
va_list args;
va_start(args, format);
while (format && format[i])
{
if (format[i] == '%')
{
i++;
switch (format[i])
{
case 'c':
j = va_arg(args, int);
write(1, &j, 1);
count++;
break;
case 's':
str = va_arg(args, char *);
if (!str)
str = "(null)";
while (str[j])
{
write(1, &str[j], 1);
j++;
count++;
}
j = 0;
break;
case '%':
write(1, &format[i], 1);
count++;
break;
default:
write(1, "%", 1);
write(1, &format[i], 1);
count += 2;
break;
}
}
else
{
write(1, &format[i], 1);
count++;
}
i++;
}
va_end(args);
return (count);
}
