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
 * @args: argument list
 * Return: number of characters printed
 */
int print_char(va_list args)
{
    return (_putchar(va_arg(args, int)));
}

/**
 * print_string - handles %s
 * @args: argument list
 * Return: number of characters printed
 */
int print_string(va_list args)
{
    char *str = va_arg(args, char *);
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
        if (format[i] == '%' && format[i + 1])
        {
            switch (format[i + 1])
            {
            case 'c':
                count += print_char(args);
                break;
            case 's':
                count += print_string(args);
                break;
            case '%':
                count += _putchar('%');
                break;
            default:
                count += _putchar(format[i]);
                count += _putchar(format[i + 1]);
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
