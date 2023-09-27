#include <stdarg.h> // For va_lis, va_start, va_arg, va_copy, va_end
#include <unistd.h> // For malloc, free, write
#include <stdio.h>

int	ft_string (char *str)
{
	int	i = -1;

	if (!str)
		return (write(1, "(null)", 6));
	while (str[++i])
		write(1, &str[i], 1);
	return (i);
}													//len_base argument specifies the base for the conversion
//int min!											//c argument represents the format specifier character that indicates the type of conversion to be performed
int ft_type_dx (long long nbr, char c, int len_base) //nbr number that needs to be converted to a string
{
    char    *base;
	int		len;

    if (c == 'd' || c == 'x')
        base = "0123456789abcdef";
	if (nbr == -2147483648)
		return (write(1, "-2147483648", 11));
	len = 0;
    if (nbr < 0)									// Handle negative numbers
    {
        len += write(1, "-", 1);					// Write "-" to stdout and update the character count
        nbr = nbr * (-1);							// Make the number positive for processing
    }
    if (nbr > (len_base - 1))						// Convert the number to a string representation
    {
        len += ft_type_dx (nbr / len_base, c, len_base);
        len += ft_type_dx (nbr % len_base, c, len_base);
    }
    else
        len += write(1, &base[nbr], 1);
    return (len);									// Return the total number of characters written
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i = 0;
	int		len = 0;

	va_start (args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 's')
				len += ft_string (va_arg(args, char *));
			else if (str[i] == 'd')
				len += ft_type_dx (va_arg(args, int), str[i], 10);
			else if (str[i] == 'x')
				len += ft_type_dx (va_arg(args, unsigned int), str[i], 16);
		}
		else
			len += write(1, &str[i], 1);
		i++;
	}
	va_end (args);
	return (len);
}


#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	size;

	size = 0;

	size = ft_printf("%s\n", "toto");
	printf("%d\n", size);
	size = printf("%s\n", "toto");
	printf("%d\n", size);
	size = ft_printf("Magic %s is %d\n", "number", 42);
	printf("%d\n", size);
	size = printf("Magic %s is %d\n", "number", 42);
	printf("%d\n", size);
	size = ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	printf("%d\n", size);
	size = printf("Hexadecimal for %d is %x\n", 42, 42);
	printf("%d\n", size);
	size = ft_printf("%d %d %x\n", INT_MAX, INT_MIN, UINT_MAX);
	printf("%d\n", size);
	size = ft_printf("%d %d %x\n", INT_MAX, INT_MIN, UINT_MAX);
	printf("%d\n", size);
	size = ft_printf("%d, %d\n", 0, -24);
	printf("%d\n", size);
	size = ft_printf("%d, %d\n", 0, -24);
	printf("%d\n", size);
	printf("%d\n", size);
	ft_printf("Hello world %\n");
	return (0);
}



/*
int main(void)
{
    printf("Testing ft_printf:\n");
    ft_printf("%s\n", "toto");
    ft_printf("Magic %s is %d\n", "number", 42);
    ft_printf("Hexadecimal for %d is %x\n", 42, 42);
    ft_printf("Hello, %s!\n", "world");
    ft_printf("Decimal: %d\n", 12345);
    ft_printf("Hexadecimal: %x\n", 255);
    ft_printf("Mixed: %d, %s, %x\n", 42, "text", 255);

    printf("\nTesting printf:\n");
    printf("%s\n", "toto");
    printf("Magic %s is %d\n", "number", 42);
    printf("Hexadecimal for %d is %x\n", 42, 42);
    printf("Hello, %s!\n", "world");
    printf("Decimal: %d\n", 12345);
    printf("Hexadecimal: %x\n", 255);
    printf("Mixed: %d, %s, %x\n", 42, "text", 255);

    return 0;
}
*/
/*
Assignment name  : ft_printf
Expected files   : ft_printf.c
Allowed functions: malloc, free, write, va_start, va_arg, va_copy, va_end
--------------------------------------------------------------------------------

Write a function named `ft_printf` that will mimic the real printf but 
it will manage only the following conversions: s,d and x.

Your function must be declared as follows:

int ft_printf(const char *, ... );

Before you start we advise you to read the `man 3 printf` and the `man va_arg`.
To test your program compare your results with the true printf.

Exemples of the function output:

call: ft_printf("%s\n", "toto");
out: toto$

call: ft_printf("Magic %s is %d", "number", 42);
out: Magic number is 42%

call: ft_printf("Hexadecimal for %d is %x\n", 42, 42);
out: Hexadecimal for 42 is 2a$

Obs: Your function must not have memory leaks. Moulinette will test that.

*/