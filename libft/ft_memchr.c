
char	*ft_memchr(const void *ptr, int c, int n)
{
	int	i;
	char	*str;

	str = (char *)ptr;
	i = 0;
	while (i < n)
	{
		if (str[i] == c)
		{
			return (&str[i]);
		}
		i++;
	}
	return (0);
}
