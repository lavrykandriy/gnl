#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif // BUFFER_SIZE

char    *ft_strchr(const char *s, int c);
size_t  ft_strlen(char *s);
char    *ft_join_and_free(char *stash, char *buffer);
char    *get_next_line(int fd);


#endif // GET_NEXT_LINE_H
