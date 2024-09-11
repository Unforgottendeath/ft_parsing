#include "parsing.h"

int	check(char c, char b)
{
	if (c == b)
		return (1);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dest;
	char	*src;

	src = (char *)s1;
	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	dest = (char *)malloc(i * sizeof(char) + 1);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

int	count_segments(char *str, char b)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (check(str[i], b) && str[i])
			i++;
		if (!check(str[i], b) && str[i])
			count++;
		while (!check(str[i], b) && str[i])
			i++;
	}
	return (count);
}

void	copy_segment(char *src, char *dest, char b)
{
	int	i;

	i = 0;
	while (src[i] && !check(src[i], b))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	**ft_split(char const *str, char c)
{
	int		count;
	char	**ptr;
	int		k;
	int		l;

	count = count_segments((char *)str, c);
	ptr = (char **)malloc((count + 1) * sizeof(char *));
	k = 0;
	while (k < count)
	{
		while (check(*str, c) && *str)
			str++;
		l = 0;
		while (!check(str[l], c) && str[l])
			l++;
		ptr[k] = (char *)malloc((l + 1) * sizeof(char));
		copy_segment((char *)str, ptr[k], c);
		str += l;
		k++;
	}
	ptr[k] = 0;
	return (ptr);
}