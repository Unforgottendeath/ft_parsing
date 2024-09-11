#include "parsing.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int is_num(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] < '0' || line[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	negative;

	negative = 1;
	res = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		++str;
	}
	return (res * negative);
}

int verify_floor(char **buffer, t_parsing *data, t_parsing_helper *helper)
{
    char **temp;
    int i;
    int error;

    error = 0;
    i = 0;
    if (!ft_strcmp("F", *buffer))
        return (0);
    temp = ft_split(*(buffer + 1), ',');
    while (temp[i])
    {
        if (!is_num(temp[i]) || ft_atoi(temp[i]) < 0 || ft_atoi(temp[i]) > 255)
            error = 1;
        i++;
    }
    if (buffer_counting(temp) != 3 || error)
    {
        data->floor = -1;
        return (free_buffer(temp, 1), 1);
    }
    data->floor = create_trgb(0, ft_atoi(temp[0]), ft_atoi(temp[1]), ft_atoi(temp[2]));
    helper->f_found++;
    free_buffer(temp, 1);
    return (1);
}

int verify_ceil(char **buffer, t_parsing *data, t_parsing_helper *helper)
{
    char **temp;
    int i;
    int error;

    error = 0;
    i = 0;
    if (!ft_strcmp("C", *buffer))
        return (0);
    temp = ft_split(*(buffer + 1), ',');
    while (temp[i])
    {
        if (!is_num(temp[i]) || ft_atoi(temp[i]) < 0 || ft_atoi(temp[i]) > 255)
            error = 1;
        i++;
    }
    if (buffer_counting(temp) != 3 || error)
    {
        data->ceil = -1;
        return (free_buffer(temp, 1), 1);
    }
    data->ceil = create_trgb(0, ft_atoi(temp[0]), ft_atoi(temp[1]), ft_atoi(temp[2]));
    helper->c_found++;
    free_buffer(temp, 1);
    return (1);
}

int ft_verify_floor_ceil(char **buffer, t_parsing *data, t_parsing_helper *helper)
{
    if (!verify_ceil(buffer, data, helper) && !verify_floor(buffer, data, helper))
        return (0);
    return (1);

}