

void *ft_memmove(void *dest, const void *src, int n)
{
	int	i;
	char *d;
	const char *s;

	d = (char *) dest;
	s = (const char *) src;
	i = 0;
	while (s[i] != '\0' && i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
