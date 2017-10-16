#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>

# include <string.h>

# include <unistd.h>

# include <fcntl.h>

typedef struct s_tetrimino t_tetrimino;

struct s_tetrimino
{
	char			grid[4][5];
	char			num;
	char			type;
	int				xdim;
	int				ydim;
	t_tetrimino		*next;
};

void		*ft_memset(void *b, int c, size_t len);

void		ft_putchar(char c);

void		ft_putstr(char const *s);

void		ft_putendl(char const *s);

char		*ft_strncpy(char *dst, const char *src, size_t len);

char		*ft_strcpy(char *dst, const char *src);

char		**ft_alloc_answer_grid(int dimensions, char **old_grid);

char		**ft_placeable(t_tetrimino *tetrimino, char **answer_grid, int dimensions, int *placeable);

void		ft_place_tetriminos(t_tetrimino *tetriminos);

void		ft_print_answer_grid(char **answer_grid, int dimensions);

int			room_check(t_tetrimino t, char **grid, int dimensions);

size_t		ft_strlen(const char *s);

#endif