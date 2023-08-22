#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include "mk_buffer.h"

/**
 * print_binary - Handles conversion specifier "b" for binary.
 * @buffer: Pointer to struct buffer.
 * @args: The unsigned int to be converted to binary.
 *
 * Return: Updated pointer to struct buffer.
 */
mk_buffer print_binary(mk_buffer buffer, va_list args)
{
	int j, len, temp;
	unsigned int num;
	int binary_arr[1000];

	num = va_arg(args, unsigned int);

	len = 0;
	while (num > 0)
	{
		temp = num % 2;
		binary_arr[len] = temp + '0'; /* Convert to ASCII character '0' or '1' */
		num /= 2;
		len++;
	}

	j = len - 1;
	while (j >= 0)
	{
		*buffer.box = binary_arr[j];
		buffer.box++;
		buffer.size++;
		j--;
	}

	buffer.box--; /* Adjust the pointer to its original position */
	return (buffer);
}

