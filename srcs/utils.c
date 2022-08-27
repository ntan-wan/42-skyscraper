#include "../includes/rush01.h"

//remember to free
int	*atoi_clues(char **splitted_clues)
{
	int	i;
	int	*int_clues;

	int_clues = malloc(sizeof(int) * (TOTAL_CELLS + 1));
	i = -1;
	while (splitted_clues[++i])
		int_clues[i] = ft_atoi(splitted_clues[i]);
	int_clues[TOTAL_CELLS] = 0;
	return (int_clues);
}

void	putstr_fd(char *c, int fd)
{
	write(fd, c, ft_strlen(c));
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
				c = ft_itoa((*board)[i][j].possible_num[k]);
				putstr_fd(c, 1);
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
			c = ft_itoa((*board)[i].possible_num[j]);
			putstr_fd(c, 1);
		}
		if ((i + 1) % N == 0)
			putstr_fd("\n", 1);
		else
			putstr_fd(" ", 1);
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
				(*board)[i][j].possible_num[k] = k + 1;
		}
	}
}*/

void	init_values(t_cell **board)
{
	int	i;
	int	j;

	i = -1;
	while (++i < TOTAL_CELLS)
	{
		j = -1;
		while (++j < TOTAL_COLS)
			(*board)[i].possible_num[j] = j + 1;
	}
}

//remember to free
/*t_cell	*insert_row(void)
{
	t_cell	*row;

	row = malloc(sizeof(t_cell) * (TOTAL_COLS + 1));
	if (!row)
		return (NULL);
	row[TOTAL_COLS].possible_num[0] = 0;
	return (row);
}*/

//remember to free
void	init_board(t_cell **board)
{
	int		i;
	int		j;
	t_cell	new_cell;

	*board = malloc(sizeof(t_cell) * (TOTAL_CELLS + 1));
	if (!board)
		return ;
	(*board)[TOTAL_ROWS].possible_num[0] = 0;
	i = -1;
	while (++i < TOTAL_CELLS)
		(*board)[i] = new_cell;
}
//
void	reverse_indices_arr(int	**arr)
{
	int	start;
	int	end;
	int	temp;
	int	length;

	length = -1;
	while ((*arr)[++length] != -1);
	start = -1;
	end	= length;
	while (++start < --end)
	{
		temp = (*arr)[start];
		(*arr)[start] = (*arr)[end];
		(*arr)[end] = temp;
	}
}

int	*get_cell_indices_row_index(int row_index, int n)
{	
	int	i;
	int	*cell_indicies;

	cell_indicies = malloc(sizeof(int) * (n + 1));
	if (!cell_indicies)
		return (NULL);
	cell_indicies[n] = -1;
	i = -1;
	while (++i < TOTAL_COLS)
		cell_indicies[i] = row_index * n + i;
	return (cell_indicies);
}

int	*get_cell_indices_col_index(int col_index, int n)
{	
	int	i;
	int	*cell_indicies;

	cell_indicies = malloc(sizeof(int) * (n + 1));
	if (!cell_indicies)
		return (NULL);
	cell_indicies[n] = -1;
	i = -1;
	while (++i < TOTAL_COLS)
		cell_indicies[i] = col_index + i * n;
	return (cell_indicies);
}

int	*get_cell_indices_clue_index(int clue_index, int n)
{
	int	*cell_indices;

	if (clue_index < n)
		cell_indices = get_cell_indices_col_index(clue_index, n);
	else if (clue_index >= n && clue_index < 2 * n)
	{
		cell_indices = get_cell_indices_col_index(clue_index - n, n);
		reverse_indices_arr(&cell_indices);
	}
	else if (clue_index >= 2 * n && clue_index < 3 * n)
		cell_indices = get_cell_indices_row_index(clue_index - (2 * n), n);
	else if (clue_index >= 3 * n && clue_index < 4 * n)
	{
		cell_indices = get_cell_indices_row_index(clue_index - (3 * n), n);
		reverse_indices_arr(&cell_indices);
	}
	else
		return (NULL);
	return (cell_indices);
}

void	solve_edge_clues(t_cell **board, int *int_clues)
{
	int	i;
	int	j;
	int	k;
	int	n;
	int	*cell_indices;

	i = -1;
	n = N + 1;
	while (int_clues[++i])
	{
		cell_indices = get_cell_indices_clue_index(i, N);
		if (int_clues[i] == 1)
		{
			j = -1;
			while (cell_indices[++j] != -1)
			{	
				n--;
				k = -1;
				while (++k < TOTAL_COLS)
				{
					if ((*board)[cell_indices[j]].possible_num[k] != n)
					(*board)[cell_indices[j]].possible_num[k] = 0;
				}

			}
		}

	}

}