#include <stdarg.h> // For va_lis, va_start, va_arg, va_copy, va_end
#include <unistd.h> // For malloc, free, write
#include <stdio.h>

/* printf 72 lines */
int	ft_string(char *str)
{
	int	i = -1;

	if (!str)
		return (write(1, "(null)", 6));
	while (str[++i])
		write(1, &str[i], 1);
	return (i);
}

int ft_type_dx(long long nbr, char c, int len_base)
{
    char    *base;
    int     len;

    if (c == 'd' || c == 'x')
        base = "0123456789abcdef";
    len = 0;
	if (nbr == -2147483648)
		return (write(1, "-2147483648", 11));
    if (nbr < 0)
    {
        len += write(1, "-", 1);
        nbr = nbr * -1;
    }
    if (nbr > (len_base -1))
    {
        len += ft_type_dx(nbr / len_base, c, len_base);
        len += ft_type_dx(nbr % len_base, c, len_base);
    }
    else
        len += write(1, &base[nbr], 1);
    return (len);
}

int	ft_work_types(va_list *args, char c)
{
	if (c == 's')
		return (ft_string(va_arg((*args), char *)));
	else if (c == 'd')
		return (ft_type_dx(va_arg((*args), int), c, 10));
	else if (c == 'x')
		return (ft_type_dx(va_arg((*args), unsigned int), c, 16));
	else if (c == '%')
		return (ft_string("%"));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_work_types(&args, str[i + 1]);
			i++;
		}
		else
			len += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
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