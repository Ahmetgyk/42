

void *ft_memcpy(void *dest, const void *src, int n)
{
	int	i;

	char	*dstr;
	char	*sstr;

	dstr = (char *)dest;
	sstr = (char *)src;

	i = 0;

	if (!src)
		return (0);

	while (sstr[i] != '\0' && i < n)
	{
		dstr[i] = sstr[i];
		i++;
	}
	return (dest);

}
