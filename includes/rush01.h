/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 20:21:51 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/29 17:16:39 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# define N 4
# define TOTAL_ROWS N 
# define TOTAL_COLS N 
# define TOTAL_CELLS N * N

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_cell
{
	int	nums[N];
	int	size;
}	t_cell;

/* edge */
void	edge_clues(t_cell **board, int *int_clues);

/* constraint */
void	propagate_constraint(t_cell **board);

/* eliminate */
void	process_elimination(t_cell **board);

/* init */
void	init_board(t_cell **board);
void	init_values(t_cell **board);
void	init_size(t_cell **board, int cell_index);

/* get */
int		*get_cell_indices_row_index(int row_index);
int		*get_cell_indices_col_index(int col_index);
int		*get_cell_indices_clue_index(int clue_index);

/* utils */
size_t	utils_strlen(const char *str);
void	utils_putstr_fd(char *c, int fd);
void	utils_print_board(t_cell **board);
int		utils_dup_check(t_cell **board, int cell_index, int *row_col, int num);
void	utils_free_all(t_cell **board, int **int_clues, char ***splitted_clues);

/* ft */
char	*ft_itoa(int n);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *str);
char	**ft_split(char const *s, char c);

/* cell */
void	remove_all_left_one(t_cell **board, int cell_index, int num);
int		remove_dup_num(t_cell **board, int cell_index, int *row_col, int num);
#endif