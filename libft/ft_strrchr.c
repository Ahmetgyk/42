
char	*ft_strrchr(const char *str, int c)
{
	int	i;
	char *ptr;

	ptr = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			*ptr = str[i];
		}
		i++;
	}
	return (ptr);
}
