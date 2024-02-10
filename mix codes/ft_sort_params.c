#include <unistd.h>

// Function to print a character to the standard output
void	ft_putchar(char c)
{
	write (1, &c, 1);
}

// Function to print a string to the standard output
void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		ft_putchar(str[i++]);
}

// Function to compare two strings lexicographically
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] == s2[i])
			i++;
		else if (s1[i] < s2[i] || s1[i] > s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}

// Function to swap two string pointers
void	ft_swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

// Main function
int	main(int argc, char **argv)
{
	int		j;
	int		x;

	x = 1;
	while (x < argc - 1)
	{
		j = 1;
		while (j < argc - 1)
		{
			// Compare adjacent strings and swap them if necessary
			if (ft_strcmp(argv[j], argv[j + 1]) > 0)
			{
				ft_swap(&argv[j], &argv[j + 1]);
			}
			j++;
		}
		x++;
	}
	j = 1;
	// Print sorted strings
	while (j < argc)
	{
		ft_putstr(argv[j]);
		ft_putchar('\n');
		j++;
	}
	return (0);
}
