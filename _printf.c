#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
/**
* _putchar - This function prints a character using the putchar function.
*
* @x : character parameter
* Return: 1 (success)
*        -1 (failure)
*/  
int _putchar(char x)
{
return (write(1, &x, 1));
}

int _printf(const char *format, ...)
{
va_list args;
int count = 0;
va_start (args, format);
while (*format != '\0')
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'c':
{
int c = va_arg(args, int);
_putchar(c);
count++;
break;
}
case 's':
{
char *s = va_arg(args, char *);
while (*s != '\0')
{
_putchar(*s);
s++;
count++;
}
break;
}
case '%':
{
_putchar ('%');
count++;
break;
}
default:
{
_putchar ('%');
_putchar (*format);
count += 2;
break;
}
}
}
else
{
_putchar (*format);
count++;
}
format++;
}
va_end(args);
return (count);
}
