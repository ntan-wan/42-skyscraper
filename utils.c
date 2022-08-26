#include "../includes/rush01.h"

/*int	**get_cell_indicies_from_row_index(int	row_index)
{
	int *cell_indicies;

	cell_indicies = malloc(sizeof(int *) * (N + 1));
	cell_indicies[N] = 
}*/

int	*char_to_int_clues(char	**splitted_clues)
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

void	util_print_arr(int	**arr)
{
	int	i;
	int	j;
	//int	k;

	i = 0;
	while (i < N + 2)
	{
		j = 0;
		while (j < N + 2)
		{
			//k = arr[i][j] + '0';
			//write(1, &k, 1);
			printf("%d|", arr[i][j]);
			j++;
		}
		//write(1, "\n", 1);
		printf("\n");
		i++;
	}
}

//remember to free
int	*insert_row(void)
{
	int	*row;

	row = malloc(sizeof(int) * (N + 2));
	if (!row)
		return NULL;
	//row[N + 2] = 0;
	return (row);
}

//remember to free
void	init_board(void)
{
	int	**board;
	int	i;
	int	j;

	board = malloc(sizeof(int *) * (N + 2));
	board[N + 2] = NULL;
	i = -1;
	while (++i < N + 2)
		board[i] = insert_row();
	i = -1;
	while (++i < N + 2)
	{
		j = -1;
		while (++j < N + 2)
			board[i][j] = j;
	}

	//printf("%d\n" ,board[0][0]);
	util_print_arr(board);
	//int	*row;

	///row = insert_row();
	//row[1] = 2;
}

void	init_board(void)
{
	int	**board;
	int	i;
	int	j;

	board = malloc(sizeof(int *) * (N + 2));
	board[N + 2] = NULL;
	i = -1;
	while (++i < N + 2)
		board[i] = insert_row();
	i = -1;
	while (++i < N + 2)
	{
		j = -1;
		while (++j < N + 2)
			board[i][j] = j;
	}

	//printf("%d\n" ,board[0][0]);
	util_print_arr(board);
	//int	*row;

	///row = insert_row();
	//row[1] = 2;
}