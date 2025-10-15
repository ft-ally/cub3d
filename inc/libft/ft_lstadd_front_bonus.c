/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:29:12 by tcakir-y          #+#    #+#             */
/*   Updated: 2024/12/09 20:41:54 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Adds the node ’new’ at the beginning of the list.
lst: The address of a pointer to the first link of
a list.
new: The address of a pointer to the node to be
added to the list.
*/
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new -> next = *lst;
	*lst = new;
}

//static void	print_list(t_list *list)
//{
//	while (list != NULL)
//	{
//		printf(" %s ->", (char *)list -> content);
//		list = list -> next;
//	}
//	printf(" end.\n");
//}
//int main(void)
//{
//	t_list	*list = ft_lstnew("!");
//	print_list(list);
//	ft_lstadd_front(&list, ft_lstnew(" world"));
//	ft_lstadd_front(&list, ft_lstnew("hello"));
//	print_list(list);
//	return (0);
//}
