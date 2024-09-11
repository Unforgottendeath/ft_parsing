#include "parsing.h"

char    **get_file(char *string)
{
    int     fd;
    int     i;
    char    *str;
    char    **file;

    file = malloc(MAX_LINE * sizeof(char *));
    i = 0;
    fd = open(string, O_RDONLY);
    if (fd < 0)
    {
        write(2, "Error\n", 7);
        perror(string);
        exit(1);
    }
    str = ft_substr(get_next_line(fd));
    while (str)
    {
        file[i++] = str;
        str = ft_substr(get_next_line(fd));
    }
    file[i++] = str;
    return file;
}