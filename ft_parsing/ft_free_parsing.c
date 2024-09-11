#include "parsing.h"

void    free_buffer(char **buffer, int flag)
{
    int i;

    i = 0;
    while (buffer[i])
        free(buffer[i++]);
    if (flag)
        free(buffer);
}

void    ft_free_parsing(int exit_numb, t_parsing *data)
{
    free_buffer(data->map, 0);
    free(data->north);
    free(data->south);
    free(data->west);
    free(data->east);
    exit(exit_numb);
}
