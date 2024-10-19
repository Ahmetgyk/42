
int	ft_atoi(char *str)
{
	int	i;
	int	c;
	int	n;

	i = 0;
	c = 1;
	n = 0;

	if (str[i] == '-')
	{
		c *= -1;
		i++;
	}

	while (str[i] != '\0')
	{
        if (!(str[i] == '+' || ('0' <= str[i] && str[i] <= '9')))
		    return (n * c);

        else if ('0' <= str[i] && str[i] <= '9')
        {
            n *= 10;
	        n += (str[i] - 48); 
        }
        i++;
	}
	return (0);
}
