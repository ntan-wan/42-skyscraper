#include "../includes/rush01.h"

void	utils_putstr_fd(char *c, int fd)
{
	write(fd, c, utils_strlen(c));
}

size_t	utils_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	duplicate_check(t_cell **board, int cell_index, int *row_col, int num)
{
	int	i;
	int	j;

	i = -1;
	while (++i < N)
	{
		j = -1;
		while (++j < TOTAL_COLS)
		{
			if (row_col[i] != cell_index && (*board)[row_col[i]].nums[j] == num)
				return (1);
		}
	}
	return (0);
}

void	util_print_board(t_cell **board)
{
	int		i;
	int		j;
	char	*c;

	i = -1;
	while (++i < TOTAL_CELLS)
	{
		j = -1;
		while (++j < TOTAL_COLS)
		{
			c = ft_itoa((*board)[i].nums[j]);
			utils_putstr_fd(c, 1);
		}
		if ((i + 1) % N == 0)
			utils_putstr_fd("\n", 1);
		else
			utils_putstr_fd(" ", 1);
	}
}