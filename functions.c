#include <stdarg.h>
#include <stdio.h>
#include "main.h"
int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	int charCount = 0; /* To keep track of the number of characters printed */

	while (*format != '\0')
	{
		if (*format == '%') {
		format++; /* Move past '%' */

		/* Handle conversion specifiers */
		switch (*format)
		{
			case 'c':
				charCount += putchar(va_arg(args, int));
				break;
			case 's':
				{
					const char *str = va_arg(args, const char *);
					while (*str != '\0')
					{
						charCount += putchar(*str);
						str++;
					}
					break;
				}
			case 'd':
			case 'i':
				{
					  int num = va_arg(args, int);
					  charCount += printf("%d", num); /* Using printf to handle integer printing */
					  break;
				}
			case '%':
				charCount += putchar('%');
				break;
			default:
				/* Ignore unknown specifiers */
				break;
		}
		}
		else
		{
			charCount += putchar(*format);
		}
		format++;
	}
	va_end(args);
	return charCount;
}

int main(void)
{
	_printf("Hello, %s! The character is %c. The number is %d and %i. Here's a percent sign %%.\n", "world", 'A', 42, -123);
	return 0;
}

