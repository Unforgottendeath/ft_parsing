#include "parsing.h"

int is_wall(char c)
{
    return (c == '1');
}

int is_zero(char c)
{
    return (c == '0');
}

char is_orientation(char c)
{
    if (c == 'N')
        return 'N';
    if (c == 'S')
        return 'S';
    if (c == 'E')
        return 'E';
    if (c == 'W')
        return 'W';
    return 0;
}

int ft_verify_first_last_line(char *line)
{
    char **temp;
    int i;
    int j;

    i = 0;
    temp = ft_split(line, ' ');
    while (temp[i])
    {
        j = 0;
        while (temp[i][j])
        {
            if (!is_wall(temp[i][j]))
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

// int ft_verify_map(t_parsing *data)
// {
//     int i;

//     i = 0;
//     while (data->map[i])
//     {
//         if (!i || !data->map[i + 1])
//         {
//             if (!ft_verify_first_last_line(data->map[i]))
//                 return (0);
//         }
//         else
//         {
//             if (!ft_verify_regular_line(data->map[i]))
//                 return (0);
//         }
//         i++;
//     }
//     return (1);
// }

int is_surrounded(char *line)
{
    char **temp;
    int i;

    temp = ft_split(line, ' ');
    while (temp[i])
    {
        if (!is_wall(temp[i][0]) || !is_wall(temp[i][ft_strlen(temp[i]) - 1]))
        {
            free_buffer(temp, 1);
            return (0);
        }
        i++;
    }
    free_buffer(temp, 1);
    return (0);
}

int ft_verify_map(t_parsing *data)
{
    int i;
    int j;

    i = 0;
    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            if (!i || !data->map[i + 1])
            {
                if (!is_wall(data->map[i][j]) && !is_space(data->map[i][j]))
                    return (0);
            }
            else
            {
                if (!is_surrounded(data->map[i]))
                    return (0);
                if (!is_orientation(data->map[i][j]) || !is_wall(data->map[i][j]) || !is_zero(data->map[i][j]) || data->map[i][j] != ' ')
                    return (0);
                if (data->map[i][j] == '0')
                {
                    if (! check_neighbor(data->map, i, j))
                        return (0);
                }
            }
        }
    }
}