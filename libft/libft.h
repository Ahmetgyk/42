#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

int	                ft_atoi(char *str);
void	            ft_bzero(void *s, int n);
void	            * ft_calloc(int num, int size);
int                 ft_isalnum(int c);
int	                ft_isalpha(int c);
int	                ft_isascii(int c);
int	                ft_isprint(int c);
char	            *ft_memchr(const void *ptr, int c, int n);
int	                ft_memcmp(const void *ptr1, const void *ptr2, int n);
void                *ft_memcpy(void *dest, const void *src, int n);
void                *ft_memmove(void *dest, const void *src, int n);
void                *ft_memset(void *dest, int c, int n);
char	            *ft_strchr(const char *str, int c);
char	            *ft_srtdup(const char *str);
unsigned int	    ft_strlcat(char *dest, char *src, unsigned int size);
char	            *ft_strcpy(char *dest, char *src);
int	                ft_strlen(const char *s);
int	                ft_strncmp(char *s1, char *s2, unsigned int n);
char	            *ft_strnstr(char *str, char *to_find, int maxlen);
char	            *ft_strrchr(const char *str, int c);
char	            *ft_tolower(char *str);
char	            *ft_toupper(char *str);

#endif