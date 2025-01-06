#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int BUFFER_SIZE = 10;

int ft_strlen(const char *s)
{
    unsigned int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

char *ft_strjoin(char const *s1, char const *s2)
{
    char *ptr;
    int i = 0;
    int s1len = ft_strlen(s1);
    int s2len = ft_strlen(s2);
    
    ptr = malloc(s1len + s2len + 1);
    
    if (ptr == NULL)
        return NULL;

    while (i < s1len) {
        ptr[i] = s1[i];
        i++;
    }

    for (int j = 0; j < s2len; j++) {
        ptr[i + j] = s2[j];
    }
    ptr[i + s2len] = '\0';
    return ptr;
}

int ft_strchr(const char *str, int c)
{
    unsigned char uc = (unsigned char)c;
    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] == (char)uc)
            return 1;
        i++;
    }

    if (uc == '\0')
        return 1;
    return 0;
}

void *ft_memset(void *dest, int c, size_t n)
{
    size_t i;
    char *d = (char *)dest;

    for (i = 0; i < n; i++)
    {
        d[i] = (char)c;
    }
    return d;
}

void *ft_calloc(size_t num, size_t size)
{
    void *ptr = malloc(num * size);
    if (!ptr)
        return NULL;
    ft_memset(ptr, 0, num * size);
    return ptr;
}

char *read_text(int fd, char *text)
{
    char *buffer = ft_calloc(BUFFER_SIZE + 1, 1);
    int n = 1;

    while (!ft_strchr(buffer, '\n') && n > 0) {
        n = read(fd, buffer, BUFFER_SIZE);
        if (n < 0) {
            free(buffer);
            return NULL; 
        }
        buffer[n] = '\0';
        text = ft_strjoin(text, buffer);
    }
    free(buffer);
    return text;
}

char *find_line(char *text)
{
    int i = 0;
    char *line;

    while (text[i] != '\n' && text[i] != '\0') {
        i++;
    }

    line = malloc(i + 2);
    if (!line)
        return NULL;

    for (int j = 0; j <= i; j++) {
        line[j] = text[j];
    }
    line[i + 1] = '\0';

    return line;
}

char *upgrade_text(char *text)
{
    int i = 0;
    while (text[i] != '\n' && text[i] != '\0') {
        i++;
    }

    if (text[i] == '\0') {
        free(text);
        return NULL; 
    }

    char *str = malloc(ft_strlen(text) - i); 
    if (!str)
        return NULL;

    for (int j = i + 1; text[j] != '\0'; j++) {
        str[j - i - 1] = text[j];
    }
    str[ft_strlen(str)] = '\0';
    free(text); 

    return str;
}

char *get_next_line(int fd)
{
    static char *text = NULL;
    char *line;

    if (fd == -1 || BUFFER_SIZE <= 0) {
        return NULL;
    }

    text = read_text(fd, text);
    if (!text) return NULL;  

    line = find_line(text);
    text = upgrade_text(text);

    return line;
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
