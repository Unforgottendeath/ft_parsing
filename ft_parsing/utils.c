#include "parsing.h"

size_t  ft_strlen(char *str)
{
    if (!str || !*str)
        return 0;
    else
        return (1 + ft_strlen(str + 1));
}

int ft_strcmp(char *s1, char *s2)
{
    if (!*s1 && !*s2)
        return (1);
    else if (*s1 != *s2)
        return (0);
    else
        return (ft_strcmp(s1 + 1, s2 + 1));
}