#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "common.h"
# include "ft_stacks.h"

typedef struct s_pair
{
	int	src_idx;
	int	dst_idx;
}	t_pair;

typedef struct s_push_swap_data
{
	t_stacks			*stacks;
	t_ftfrwlist_node	*cur_a;
	t_ftfrwlist_node	*cur_b;
}	t_push_swap_data;

int		push_swap(int *numbers, int count);

t_bool	ft_is_sorted(const int *numbers, int count);
t_pair	*ft_get_dest_idx(int *numbers, int count);

void	ft_sort_3(t_stacks *stacks);
void	ft_insert_next(t_push_swap_data *data);

void	ft_stacks_execute(t_stacks *this, t_instruction ins);
void	ft_stacks_execute_multiple(t_stacks *this, t_instruction ins,
								int count);

#endif // PUSH_SWAP_H
