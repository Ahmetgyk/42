

void	ft_bzero(void *s, int n)
{
	int	i;
	char	*str;

	str = (char *)s;

	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
