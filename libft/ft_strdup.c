#include <stdlib.h>

char	* ft_srtdup(const char *str)
{
	char	*mal;
	char	*ptr;
	int len;

	len = ft_strlen(str);
	mal = (char *) malloc(len);

	if (mal == NULL){
		return (NULL);
	}

	ptr = (char *) ft_memcpy(mal, str, len);
	return (ptr);
}
