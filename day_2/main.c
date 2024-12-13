#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	check_report(char	*line)
{
	char **split_line = ft_split(line, ' ');

	int	*tab;
	int	i = 0;
	tab = (int *)malloc(sizeof(int) * 8);
	while (split_line[i])
	{
		tab[i] = atoi(split_line[i]);
		i++;
	}
	i--;
	int end = i;
	int order;
	if (tab[0] > tab[i])
		order = -1;
	else if (tab[0] < tab[i])
		order = 1;
	else
		return (0);
	i = 0;
	if (order == 1)
	{
		while (i < end)
		{
			if (tab[i] >= tab[i + 1] || abs(tab[i] - tab[i + 1]) > 3)
				return (0);
			i++;
		}
	}
	if (order == -1)
	{
		while (i < end)
		{
			if (tab[i] <= tab[i + 1] || abs(tab[i] - tab[i + 1] > 3))
				return (0);
			i++;
		}
	}
	return (1);
}

int	main(void)
{
	int	count = 0;
	int	fd = open("input.txt", O_RDONLY);
	char	*line = get_next_line(fd);
	while (line)
	{
		count += check_report(line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	printf("%d\n", count);
}