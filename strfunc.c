#include "shell.h"

/**
 * _puts - Writes a string to standard output
 * @str: String to write
 * Return: -1 on failure or number of chars printed
 */
ssize_t _puts(char *str)
{
	ssize_t num, len;

	num = _strlen(str);
	len = write(STDOUT_FILENO, str, num);

	if (len != num)
	{
		perror("Fatal Error");
		return (-1);
	}
	return (len);
}

/**
 * _strdup - Pointer to be returned to new mem alloc space which contains copy
 * @strtodup: A string to be duplicated
 * Return: A pointer to the new duplicated string
 */
char *_strdup(char *strtodup)
{
	char *copy;

	int len, j;

	if (strtodup == 0)
		return (NULL);
	for (len = 0; strtodup[len]; len++)
		;
	copy = malloc((len + 1) * sizeof(char));

	for (j = 0; j <= len; j++)
		copy[j] = strtodup[j];

	return (copy);
}

/**
 * _strcmpr - Two strings to be compared
 * @strcmp1: The first string of two, to be compared
 * @strcmp2: The second string of two, to be compared
 * Return: 0 if successful anything else is a failure
 */
int _strcmpr(char *strcmp1, char *strcmp2)
{
	int j;

	j = 0;
	while (strcmp1[j] == strcmp2[j])
	{
		if (strcmp1[j] == '\0')
			return (0);
		j++;
	}
	return (strcmp1[j] - strcmp2[j]);
}

/**
 * _strcat - Two strings to be concatenated
 * @strc1: First string
 * @strc2: Second string
 * Return: Pointer
 */
char *_strcat(char *strc1, char *strc2)
{
	char *newstring;
	unsigned int len1, len2, newlen, j, k;

	len1 = 0;
	len2 = 0;
	if (strc1 == NULL)
		len1 = 0;
	else
	{
		for (len1 = 0; strc1[len1]; len1++)
			;
	}
	if (strc2 == NULL)
		len2 = 0;
	else
	{
		for (len2 = 0; strc2[len2]; len2++)
			;
	}
	newlen = len1 + len2 + 2;
	newstring = malloc(newlen * sizeof(char));
	if (newstring == NULL)
		return (NULL);
	for (j = 0; j < len1; j++)
		newstring[j] = strc1[j];
	newstring[j] = '/';
	for (k = 0; k < len2; k++)
		newstring[j + 1 + k] = strc2[k];
	newstring[len1 + len2 + 1] = '\0';

	return (newstring);
}

/**
 * _strlen - The length of a string to be returned
 * @str: String to be measured
 * Return: The length of string
 */
unsigned int _strlen(char *str)
{
	unsigned int len;

	len = 0;

	for (len = 0; str[len]; len++)
		;
	return (len);
}

