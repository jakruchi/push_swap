#include <stdio.h>

int	ft_safe_atoi(const char *str, int *error)
{
	long int	result;
	int			sign;

	result = 0;
	sign = 1;
	*error = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		if ((result * sign) > 2147483647 || ((result * sign) < -2147483648))
			return (*error = 1, 0);
		str++;
	}
	if (*str != '\0')
		*error = 1;
	return ((int)(result * sign));
}

int	main(int argc, char **argv)
{
	int	number;
	int	error;

	if (argc != 2)
		return (1);
	number = ft_safe_atoi(argv[1], &error);
	if (error == 1)
		printf("number failed.\n");
	else
		printf("%d\n", number);
	return (0);
}
