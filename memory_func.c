#include "shell.h"
/**
 * *_mems - fills memory with a constant byte
 * @s: the pointer to the memory area
 * @b: the byte to fill *s with
 * @n: the amount of bytes to be filled
 * Return: (s) a pointer to the memory area s
 */
char *_mems(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}
/**
 * free - frees a string of strings
 * @p: string of strings
 */
void fre(char *p)
{
	char **a = p;

	if (!p)
		return;
	while (*p)
		free(*p++);
	free(a);
}
/**
 * _lloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old: byte size of previous block
 * @new_s: byte size of new blocj
 * Return: pointer to da ol block nameen.
 */
void *_lloc(void *ptr, unsigned int old, unsigned int new_s)
{
	char *p;

	if (!ptr)
		return (malloc(new_s));
	if (!new_s)
		return (free(ptr), NULL);
	if (new_s == old)
		return (ptr);
	p = malloc(new_s);
	if (!p)
		return (NULL);
	old = old < new_s ? old : new_s;
	while (old--)
		p[old] = ((char *)ptr)[old];
	free(ptr);
	return (p);
}
