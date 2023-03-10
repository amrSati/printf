#include "main.h"

/**
 * handle_fmt - handles printing formats specifieres
 * @format: formatted string
 * @args: arguments list
 * @ind: pointer to format index
 *
 * Return: number of bytes printed
 */
int handle_fmt(const char *format, va_list args, int *ind)
{
	int i, printed_chars = 0;
	fmt_t types[] = {
		{'c', print_char},
		{'s', print_str},
		{'%', print_percent},
		{'\0', NULL}
	};

	for (i = 0; types[i].fmt != '\0' && format[*ind] != '\0'; i++)
		if (format[*ind] == types[i].fmt)
		{
			printed_chars += (types[i].func(args));
			break;
		}

	if (types[i].fmt == '\0')
	{
		if (format[*ind] != '\0')
			printed_chars += write(1, &format[(*ind - 1)], 2);
		else
			return (printed_chars);
	}

	return (printed_chars);
}
