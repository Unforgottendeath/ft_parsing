#include "parsing.h"

int is_wall(char c)
{
    if (c == '1')
        return (1);
    return (0);
}

int is_space(char c)
{
    if (c == ' ')
        return (1);
    return (0);
}

int is_orientation(char c)
{
    if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
        return (1);
    return (0);
}

int is_empty_space(char c)
{
    if (c == '0')
        return (1);
    return (0);
}

int ft_check_entity(char c)
{
    if (!is_empty_space(c) && !is_orientation(c) && !is_space(c) && !is_wall(c))
        return (0);
    return (1);
}