
int	ft_memcmp(const void *ptr1, const void *ptr2, int n)
{
	int	i;
	char	*str1;
	char	*str2;

	str1 = (char *)ptr1;
	str2 = (char *)ptr2;

	i = 0;
	while ((str1[i] != '\0' || str2[i] != '\0') && i < n)
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		i++;
	}
	return (0);
}
