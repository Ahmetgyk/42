#include <stdlib.h>

void	* ft_calloc(int num, int size)
{
	void	*ptr;

	ptr = malloc(num * size);
	return (ptr);
}
