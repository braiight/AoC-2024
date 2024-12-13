#include <fcntl.h>
#include "utils.h"
#include <stdio.h>

void	bubble_sort(int *tab, int size)
{
	int	i;
	int	temp;

	while (size > 0)
	{
		i = 0;
		while (i < (size - 1))
		{
			if (tab[i] > tab[i + 1])
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
			}
			i++;
		}
		size--;
	}
}



int	main(void)
{
	int		fd = open("input.txt", O_RDONLY);
	char	*line = get_next_line(fd);
	int		*tab_1 = (int *)malloc(sizeof(int) * 1000);
	int		*tab_2 = (int *)malloc(sizeof(int) * 1000);
	char	**split_line;
	int		i = 0;

	while (line)
	{
		split_line = ft_split(line, ' ');
		tab_1[i] = atoi(split_line[0]);
		tab_2[i] = atoi(split_line[1]);
		free(split_line[0]);
		free(split_line[1]);
		free(split_line);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	bubble_sort(tab_1, 1000);
	bubble_sort(tab_2, 1000);
	int test = 0;
	while (test < 1000)
	{
		printf("%d    %d\n", tab_1[test], tab_2[test]);
		test++;
	}
	i = 0;
	int res = 0;
	while (i < 1000)
	{
		res += abs(tab_1[i] - tab_2[i]);
		printf("%d\n", res);
		i++;
	}
	printf("%d\n", res);
	free(tab_1);
	free(tab_2);
	return (0);
}