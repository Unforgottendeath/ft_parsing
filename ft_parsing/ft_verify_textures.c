#include "parsing.h"

int verify_west(char **buffer, t_parsing *data, t_parsing_helper *helper)
{
    if (!ft_strcmp("WE", *buffer))
        return (0);
    if (!helper->we_found)
        data->west = ft_strdup(*(buffer + 1));
    helper->we_found++;
    return (1);
}

int verify_east(char **buffer, t_parsing *data, t_parsing_helper *helper)
{
    if (!ft_strcmp("EA", *buffer))
        return (0);
    if (!helper->ea_found)
        data->east = ft_strdup(*(buffer + 1));
    helper->ea_found++;
    return (1);
}

int verify_south(char **buffer, t_parsing *data, t_parsing_helper *helper)
{
    if (!ft_strcmp("SO", *buffer))
        return (0);
    if (!helper->so_found)
        data->south = ft_strdup(*(buffer + 1));
    helper->so_found++;
    return (1);
}

int verify_north(char **buffer, t_parsing *data, t_parsing_helper *helper)
{
    if (!ft_strcmp("NO", *buffer))
        return (0);
    if (!helper->no_found)
        data->north = ft_strdup(*(buffer + 1));
    helper->no_found++;
    return (1);
}

int ft_verify_textures(char **buffer, t_parsing *data, t_parsing_helper *helper)
{
    if (!verify_east(buffer, data, helper) && !verify_west(buffer, data,helper) && !verify_north(buffer, data, helper) &&  !verify_south(buffer, data, helper))
        return (0);
    return (1);
}