#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int BUFFER_SIZE = 10;

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*dest;

	i = 0;
	dest = s;
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	new = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new)
	{
		free (s1);
		return (NULL);
	}
	while (s1 && s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
		new[i++] = s2[j++];
	new[i] = '\0';
	free (s1);
	return (new);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while ((char)c != *s)
	{
		if (!*s)
			return (0);
		s++;
	}
	return ((char *)s);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;

	result = malloc(count * size);
	if (result == NULL)
		return (NULL);
	ft_bzero(result, count * size);
	return (result);
}

char	*ft_after_line(char *perm)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (perm[i] != '\0' && perm[i] != '\n')
		i++;
	if (!perm[i])
	{
		free (perm);
		return (NULL);
	}
	str = malloc(ft_strlen(perm) - i + 1);
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (perm[i])
		str[j++] = perm[i++];
	str[j] = '\0';
	free (perm);
	return (str);
}

char	*ft_one_line(char	*perm)
{
	int		i;
	char	*line;

	i = 0;
	while (perm[i] != '\n' && perm[i] != '\0')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (perm[i] != '\n' && perm[i] != '\0')
	{
		line[i] = perm[i];
		i++;
	}
	if (perm[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_find_n(char	*perm, int fd)
{
	char	*line;
	ssize_t	r;

	line = ft_calloc(1, BUFFER_SIZE + 1);
	r = 1;
	while (!ft_strchr(line, '\n') && r > 0)
	{
		r = read(fd, line, BUFFER_SIZE);
		if (r == -1)
		{
			free (line);
			free (perm);
			return (NULL);
		}
		if (r == 0 && (!perm || *perm == '\0'))
		{
			free (line);
			free (perm);
			return (NULL);
		}
		line[r] = '\0';
		perm = ft_strjoin(perm, line);
	}
	free (line);
	return (perm);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*perm;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	perm = ft_find_n(perm, fd);
	if (!perm)
	{
		free (perm);
		return (NULL);
	}
	line = ft_one_line(perm);
	perm = ft_after_line(perm);
	return (line);
}

int main()
{
    int fd = open("example.txt", O_RDONLY);

    if (fd == -1) {
        perror("File cannot be opened");
        return 1;
    }

    char *line1 = get_next_line(fd);  
    if (line1) {
        write(1, line1, ft_strlen(line1));  
        free(line1);  
    }

    char *line2 = get_next_line(fd);  
    if (line2) {
        write(1, line2, ft_strlen(line2));  
        free(line2);  
    }

    write(1, "\n", 1);

    close(fd);  
    return 0;
}
