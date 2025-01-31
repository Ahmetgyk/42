#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int BUFFER_SIZE = 10;

int ft_strchr(const char *str, int c)
{
    unsigned char uc = (unsigned char)c;
    while (str && *str)
    {
        if (*str == (char)uc)
            return 1;
        str++;
    }
    return (uc == '\0');
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0')
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
	new = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new)
	    return (s1);
	while (s1 && s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
    free(s1);
	return (new);
}

char	*read_text(int fd, char *text)
{
	char	*buffer;
	int		n;

	n = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	while (n > 0)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[n] = '\0';
		text = ft_strjoin(text, buffer);
        if (ft_strchr(buffer, '\n'))
            break;
	}
	free(buffer);
	return (text);
}

char	*find_line(char *text)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (text[i] != '\n' && text[i] != '\0')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = text[j];
		j++;
	}
	line[i] = '\n';
    line[i + 1] = '\0';
	return (line);
}

char	*upgrade_text(char *text)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (text[i] != '\n' && text[i] != '\0')
		i++;
	if (text[i] == '\0')
		return (text);
	str = malloc(ft_strlen(text) - i);
	if (!str)
		return (NULL);
	i++;
	while (text[i])
		str[j++] = text[i++];
	str[j] = '\0';
	free(text);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		*line;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	text = read_text(fd, text);
	if (!text)
		return (NULL);
	line = find_line(text);
	if (!line)
		return (NULL);
	text = upgrade_text(text);
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
