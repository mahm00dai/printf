#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes a character to stdout
 * @c: the character to print
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
}

/**
 * print_char - handles %c
 * @c: character to print
 * Return: number of characters printed
 */
int print_char(char c)
{
    return (_putchar(c));
}

/**
 * print_string - handles %s
 * @str: string to print
 * Return: number of characters printed
 */
int print_string(char *str)
{
    int i = 0;

    if (str == NULL)
        str = "(null)";

    while (str[i])
    {
        _putchar(str[i]);
        i++;
    }

    return (i);
}

/**
 * _printf - prints formatted output
 * @format: format string
 * @...: additional arguments
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;

    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%' &&
            (format[i + 1] == 'c' || format[i + 1] == 's' || format[i + 1] == '%'))
        {
            if (format[i + 1] == 'c')
            {
                count += print_char(va_arg(args, int));
            }
            else if (format[i + 1] == 's')
            {
                count += print_string(va_arg(args, char *));
            }
            else if (format[i + 1] == '%')
            {
                count += _putchar('%');
            }
            i++;
        }
        else
        {
            count += _putchar(format[i]);
        }
        i++;
    }

    va_end(args);
    return (count);
}
