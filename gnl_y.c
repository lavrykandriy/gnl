#include "get_next_line.h"

size_t  ft_strlen(char *str)
{
    int i;
    i = 0;
    while(str[i])
        i++;
    return (i);
}

char    *ft_join_and_free(char *s1, char *s2)
{
    int i;
    int j;
    char *res;

    if (!s2)
        return (free(s1), NULL);

    if (!s1)
    {
        s1 = malloc(1 * sizeof(char));
        if (!s1)
            return (NULL);
        s1[0] = '\0';
    }

    res = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
    if (!res)
        return (free(s1), NULL);
    i = -1;
    while (s1[++i])
        res[i] = s1[i];
    j = 0;
    while (s2[j])
        res[i++] = s2[j++];
    res[i] = '\0';
    free(s1);
    return(res);
}

char    *ft_strchr(const char *str, int  c)
{
    char    ch;
    ch = (char)c;
    if (!str)
	    return (NULL);
    while (*str != '\0')
    {
        if (*str == ch)
            return ((char *)str);
        str++;
    }
    if (ch == '\0')
        return ((char *)str);
    return (NULL);
}



