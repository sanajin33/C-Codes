#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int ft_strlen(char *str);
int ft_total_size(int size, char **strs, char *sep);
char *ft_strcat(char *dest, char *src);
char *ft_strjoin(int size, char **strs, char *sep);

int main(void)
{
    char *strs[] = {"Hello", "world", "!", NULL}; // Array of strings to concatenate
    char *sep = " "; // Separator between strings
    char *result; // Resulting concatenated string

    // Call ft_strjoin to concatenate the array of strings with the separator
    result = ft_strjoin(3, strs, sep);

    // Check if ft_strjoin was successful
    if (result != NULL)
    {
        // Print the concatenated string
        printf("Concatenated string: %s\n", result);

        // Free the allocated memory for the concatenated string
        free(result);
    }
    else
    {
        // Print an error message if ft_strjoin failed
        printf("Error: Memory allocation failed.\n");
    }

    return 0;
}


// Function to calculate the length of a null-terminated string
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// Function to calculate the total length of the concatenated string, including separators
int	ft_total_size(int size, char **strs, char *sep)
{
	int	i;
	int	sep_len;
	int	total_len;

	i = 0;
	sep_len = ft_strlen(sep); // Calculate the length of the separator
	total_len = 0;
	while (i < size)
	{
		total_len += ft_strlen(strs[i]); // Add the length of each string
		if (i < size - 1)
			total_len += sep_len; // Add the length of the separator if not the last string
		i++;
	}
	return (total_len);
}

// Function to concatenate two strings
char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0') // Find the end of the destination string
		i++;
	while (src[j] != '\0') // Copy characters from src to dest
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0'; // Add null terminator to the end of the concatenated string
	return (dest);
}

// Function to concatenate an array of strings with a separator
char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*text; //
	int		i;
	int		total_len; //

	i = 0;
	// Calculate the total length of the concatenated string
	total_len = ft_total_size(size, strs, sep) + 1; //
	// Allocate memory for the concatenated string
	text = malloc(sizeof(char) * total_len); 
	if (!text) // Check if memory allocation was successful
		return (0); 
	*text = 0; 

	// Concatenate each string in strs with the separator sep
	while (i < size)
	{
		ft_strcat(text, strs[i]); // Concatenate the current string
		if (i < size - 1) // Check if it's not the last string
			ft_strcat(text, sep); 
		i++;
	}
	return (text); 
}
