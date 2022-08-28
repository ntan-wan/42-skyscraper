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

/*void	util_print_board(t_cell ***board)
{
	int		i;
	int		j;
	int		k;
	char	*c;

	i = -1;
	while (++i < TOTAL_ROWS)
	{
		j = -1;
		while (++j < TOTAL_COLS) 
		{
			k = -1;
			while (++k < TOTAL_COLS)
			{
				c = ft_itoa((*board)[i][j].nums[k]);
				utils_putstr_fd(c, 1);
			}
			write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
}*/

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

/*void	init_values(t_cell ***board)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (++i < TOTAL_ROWS)
	{
		j = -1;
		while (++j < TOTAL_COLS)
		{	
			k = -1;
			while (++k < TOTAL_COLS)
				(*board)[i][j].nums[k] = k + 1;
		}
	}
}*/



//remember to free
/*t_cell	*insert_row(void)
{
	t_cell	*row;

	row = malloc(sizeof(t_cell) * (TOTAL_COLS + 1));
	if (!row)
		return (NULL);
	row[TOTAL_COLS].nums[0] = 0;
	return (row);
}*/

//remember to free

//


/*int	*get_cross_indices_cell_index(int cell_index)
{
	get_cell_indices_row_index(cell_index / N);
	get_cell_indices_col_index(cell_index % N);
}*/

int	is_one_value(int *nums)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (++i < TOTAL_COLS)
	{
		if (nums[i] > 0)
			count++;
	}
	if (count == 1)
		return (1);
	else
		return (0);
}
int	remove_num(t_cell **board, int *row_col, int num, int cell_index)
{
	int	i;
	int	j;
	int	removed;

	i = -1;
	removed = 0;
	while (row_col[++i])
	{
		j = -1;
		while (++j < TOTAL_COLS)
		{
			if (row_col[i] != cell_index && (*board)[row_col[i]].nums[j] == num)
			{
				(*board)[row_col[i]].nums[j] = 0;
				removed++;
			}
		}
	}
	return (removed);
}

void	clear_all_left_one(t_cell **board, int cell_index, int num)
{
	int	i;

	i = -1;
	while (++i < TOTAL_COLS)
	{
		if ((*board)[cell_index].nums[i] != num)
			(*board)[cell_index].nums[i] = 0;
	}
}
/*void	find_correct_sequence(t_cell **board, int *cell_indices)

{
	int	i;
	int	j;
	int	nums_count;
	int	highest_count;
	int	*sequences;
	int	blocks;

	i = -1;
	highest_count = INT_MIN;
	while (++i < TOTAL_COLS)
	{
		j = -1;
		nums_count = 0;
		while (++j < TOTAL_COLS)
		{
			if ((*board)[i].nums[j] != 0)
				nums_count++;
		}
		if (nums_count > highest_count)
			highest_count = nums_count;
	}
	blocks = highest_count * N + highest_count;
	sequences = malloc(sizeof(int) * blocks);
	//while (blocks && blocks % (N + 1) == 0)
	//{
	//	sequences[blocks - 1] = 0;
	//	blocks %= (N + 1);
	//}
	while (blocks--)
		sequences[blocks] = 0;
	i = -1;
	int	target_index;
	while (++i < TOTAL_COLS)
	{
		int k = 0;
		if (is_one_value((*board)[cell_indices[i]].nums))
		{
			j = -1;
			while (++j < TOTAL_COLS)
			{
				if ((*board)[cell_indices[i]].nums[j] != 0)
					break ;
			}
			while (highest_count - k)
			{
				target_index = i + (k * (N + 1));
				sequences[target_index] = (*board)[cell_indices[i]].nums[j];
				k++;
			}
		}
		else
		{
			int	l;
			int	m;
			int n;
			
			l = -1;
			while ( ++l < TOTAL_COLS)
			{
				m = 0;
				if ((*board)[cell_indices[i]].nums[l] != 0)
				{
					n = -1;
					while (sequences[++n])
					{
						if (sequences[n] == (*board)[cell_indices[i].nums[l]])
						{
							
						}
					}
					sequences[n] = (*board)[cell_indices[i]].nums[l];
				}
			}
		}
	}
}*/

/*

void	sequences_filtration(t_cell **board)
{
	int i;
	int	j;
	int	*cell_indices;
	int	multiple_values;

	i = -1;
	multiple_values = 0;
	while ( ++i < TOTAL_ROWS)
	{
		j = -1;
		cell_indices = get_cell_indices_row_index(i);
		while (++j < TOTAL_COLS)
		{
			if (!is_one_value((*board)[cell_indices[i]].nums))
				multiple_values = 1;
		}
		if (multiple_values)
			find_correct_sequence(board, cell_indices);
		free(cell_indices);
	}
	//i >= (2 * N) && i < (3 * N)
	//i >= (3 * N) && i < (TOTAL_CELLS);
}*/