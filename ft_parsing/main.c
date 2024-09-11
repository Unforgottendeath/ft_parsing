#include "parsing.h"

void ft_initialize_data(t_parsing *data)
{
    data->east = NULL;
    data->west = NULL;
    data->north = NULL;
    data->south = NULL;
}

int main(int ac, char **av)
{
    t_parsing   data;

    ft_initialize_data(&data);
    if (ac == 2)
    {
        if (!ft_parsing(av[1], &data))
            ft_free_parsing(1, &data);
    }
    else
    {
        return (write(2, "Error\nEnter a valid number of argument\n", 40), 1);
    }
    ft_free_parsing(0, &data);
}