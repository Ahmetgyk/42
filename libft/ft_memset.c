

void* ft_memset(void *dest, int c, int n)
{
	int	i;
	char *d;

	d = (char *) dest;
	i = 0;
	while (d[i] != '\0' && i < n)
	{
		d[i] = c;
		i++;
	}
	return (d);
}
