#include <stdarg.h>
#include <stdio.h>
#include "main.h"

int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;
	va_start(args, format);

	while (*format)
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			format++;
			switch (*format)
			{
				case 'd':
				case 'i':
					count += printf("%d", va_arg(args, int));
					break;
				case 'u':
					count += printf("%u", va_arg(args, unsigned int));
					break;
				case 'o':
					count += printf("%o", va_arg(args, unsigned int));
					break;
				case 'x':
					count += printf("%x", va_arg(args, unsigned int));
					break;
				case 'X':
					count += printf("%X", va_arg(args, unsigned int));
					break;
				case 'c':
					count += printf("%c", va_arg(args, int));
					break;
				case 's':
					count += printf("%s", va_arg(args, char *));
					break;
				case 'p':
					count += printf("%p", va_arg(args, void *));
					break;
				default:
					count += putchar('%');
					count += putchar(*format);
			}
		}
		else
		{
			count += putchar(*format);
		}
		format++;
	}

	va_end(args);
	return count;
}

