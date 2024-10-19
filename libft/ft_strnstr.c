
#include <libft.h>

char	*ft_strnstr(char *str, char *to_find, int maxlen)
{
	int	i;
	int	n;
	int	len;

	i = 0;
	n = 0;
	len = ft_strlen(to_find);
	if (to_find[i] == '\0')
		return (str);
	while (str[i] != '\0' && i < maxlen)
	{
		if (str[i] == to_find[0])
		{
			n = 0;
			while (str[n + i] && to_find[n] && str[n + i] == to_find[n])
			{
				if (n == len - 1)
					return (&str[i]);
				n++;
			}
		}
		i++;
	}
	return (NULL);
}
