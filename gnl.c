#include "get_next_line.h"

static char *clean_stash(char *stash)
{
    int i;
    int j;
    char *new_stash;

    if (!stash)
	    return (NULL);
    new_stash = NULL;
    i = 0;
    j = 0;
    if ((ft_strchr(stash, '\n')) != NULL)
    {
        while (stash[i] != '\n')
            i++;
	i++;
	if (stash[i] == '\0')
		return (free(stash), NULL);
        new_stash = malloc((ft_strlen(stash) - i + 1) * sizeof(char));
        if (!new_stash)
            return (free(stash), NULL);
        while (stash[i])
            new_stash[j++] = stash[i++];
        new_stash[j] = '\0';
        return (free(stash), new_stash);
    }
    return (free(stash), NULL);
}

static char *strim(char *s)
{
    int i;
    int flg;
    char    *res;

    if (!s)
	    return (free(s), NULL);
    flg = 0;
    i = 0;
    while (s[i] && s[i] != '\n')
        i++;
    if (s[i] == '\n')
            flg = 1;
    res = malloc(sizeof(char) * (i + 1 + flg));
    if (!res)
        return NULL;


    i = 0;
    while (s[i] && s[i] != '\n')
    {
        res[i] = s[i];
        i++;
    }
    if (flg)
    {
        res[i++] = '\n';
    }
    res[i] = '\0';
    return (res);
}

char *get_next_line(int fd)
{
    static char *stash;
    char *line;
    char *buffer;
    ssize_t read_bytes;

    if (BUFFER_SIZE < 1 || fd < 0 || BUFFER_SIZE > 21477483647)
        return (NULL);

    read_bytes = 1;
    buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buffer)
	    return (NULL);
    while ((ft_strchr(stash, '\n') == NULL) && read_bytes > 0)
    {
	    read_bytes = read(fd, buffer, BUFFER_SIZE);
	    if (read_bytes < 0)
	    {
		    free(stash);
		    stash = NULL;
		    free(buffer);
		    return (NULL);
	    }
	    buffer[read_bytes] = '\0';
	    stash = ft_join_and_free(stash, buffer);

    }
    free(buffer);

    if (!stash || !*stash)
    {
	    free(stash);
	    stash = NULL;
	    return (NULL);
    }
    line = strim(stash);
    stash = clean_stash(stash);
    return (line);
}
