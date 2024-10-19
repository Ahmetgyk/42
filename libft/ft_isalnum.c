

int	ft_isalnum(int c)
{
	if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
	{
		return (1);
	}
	if ('0' <= c && c <= '9')
	{
		return (1);
	}
	return (0);
}
