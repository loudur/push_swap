/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:42:12 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/21 23:42:14 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stacks.h"
#include "checker.h"

static void	print_item(void *value)
{
	ft_putchar_fd(' ', STDOUT);
	ft_putnbr_fd(*(int *)value, STDOUT);
}

static void	print_color(t_ftfrwlist *list)
{
	int					last_value;
	int					value;
	t_ftfrwlist_node	*node;

	node = list->first;
	if (!node)
		return ;
	last_value = *(int *)node->value;
	ft_putchar_fd(' ', STDOUT);
	ft_putstr_fd(GREEN, STDOUT);
	ft_putnbr_fd(last_value, STDOUT);
	node = node->next;
	while (node)
	{
		value = *(int *)node->value;
		if (value > last_value)
			ft_putstr_fd(GREEN, STDOUT);
		else
			ft_putstr_fd(RED, STDOUT);
		ft_putstr_fd(" ", STDOUT);
		ft_putnbr_fd(value, STDOUT);
		last_value = value;
		node = node->next;
	}
	ft_putstr_fd(RESET, STDOUT);
}

void	ft_stacks_print(t_stacks *this, t_checker_flags flags)
{
	ft_putstr_fd("a |", STDOUT);
	if (flags.color)
	{
		print_color(this->a);
		ft_putstr_fd("\nb |", STDOUT);
		print_color(this->b);
	}
	else
	{
		ft_frwlist_iter(this->a, print_item);
		ft_putstr_fd("\nb |", STDOUT);
		ft_frwlist_iter(this->b, print_item);
	}
	ft_putendl_fd("", STDOUT);
}
