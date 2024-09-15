#include "parsing.h"

void ft_initialize_data(t_parsing *data)
{
    data->east = NULL;
    data->west = NULL;
    data->north = NULL;
    data->south = NULL;
}

void ft_print(t_parsing *data)
{
    int i = 0;

    printf("\n\tMAP\t\n");
    while (data->map[i])
    {
        printf("%s\n", data->map[i]);
        i++;
    }
    printf("\n\tNORTH TEXTURE\t->\t%s\n", data->north);
    printf("\n\tSOUTH TEXTURE\t->\t%s\n", data->south);
    printf("\n\tWEST TEXTURE\t->\t%s\n", data->west);
    printf("\n\tEAST TEXTURE\t->\t%s\n", data->east);
    printf("\n\tCEIL COLOR\t->\t%d\n", data->ceil);
    printf("\n\tFLOOR COLOR\t->\t%d\n", data->floor);
    printf("\n\tPLAYER ORIENTATION\t->\t%c\n", data->direction);
}
int main(int ac, char **av)
{
    t_parsing   data;

    ft_initialize_data(&data);
    if (ac == 2)
    {
        if (!ft_parsing(av[1], &data))
            ft_free_parsing(1, &data);
        ft_print(&data);
    }
    else
    {
        return (write(2, "Error\nEnter a valid number of argument\n", 40), 1);
    }
    ft_free_parsing(0, &data);
}