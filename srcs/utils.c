#include "../includes/rush01.h"

//remember to free
int	*atoi_clues(char **splitted_clues)
{
	int	i;
	int	*int_clues;

	int_clues = malloc(sizeof(int) * (N * N + 1));
	i = -1;
	while (splitted_clues[++i])
		int_clues[i] = ft_atoi(splitted_clues[i]);
	int_clues[N * N] = 0;
	return (int_clues);
}

void	util_print_board(t_cell ***board)
{
	int	i;
	int	j;
	int	k;
	int	c;

	i = -1;
	while (++i < TOTAL_ROWS)
	{
		j = -1;
		while (++j < TOTAL_COLS) 
		{
			k = -1;
			while (++k < TOTAL_COLS)
			{
			//character = (*board)[i][j] + '0';
				c = (*board)[i][j].possible_num[k] + '0';
				write(1, &c, 1);
			}
			write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
}

/*void	init_value(int ***board, int value)
{
	int	i;
	int	j;

	i = -1;
	while (++i < TOTAL_ROWS)
	{
		j = -1;
		while (++j < TOTAL_COLS)
			(*board)[i][j] = value;
	}
}*/

void	init_values(t_cell ***board)
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
}

//remember to free
t_cell	*insert_row(void)
{
	t_cell	*row;

	row = malloc(sizeof(t_cell) * (TOTAL_COLS + 1));
	if (!row)
		return (NULL);
	//row[TOTAL_COLS] = 0;
	return (row);
}

//remember to free
void	init_board(t_cell ***board)
{
	int	i;
	int	j;

	*board = malloc(sizeof(t_cell *) * (TOTAL_ROWS + 1));
	if (!board)
		return ;
	(*board)[TOTAL_ROWS] = NULL;
	i = -1;
	while (++i < TOTAL_ROWS)
		(*board)[i] = insert_row();
}

