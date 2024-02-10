#include <stdio.h>

int	ft_atoi(char *str)
{
	int	i;
	int	s;
	int	result;

	i = 0;
	s = 1;
	result = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s = s * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (str[i] - 48) + (result * 10);
		i++;
	}
	return (result * s);
}

int main(void)
{
	char *str = "  -42"; // Example string containing an integer

	// Call ft_atoi to convert the string to an integer
	int result = ft_atoi(str);

	// Print the result
	printf("Result: %d\n", result);

	return 0;
}