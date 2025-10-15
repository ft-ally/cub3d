/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:09:01 by tcakir-y          #+#    #+#             */
/*   Updated: 2025/04/20 19:38:25 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Adds the node ’new’ at the end of the list.*/
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*end_of_list;

	end_of_list = ft_lstlast(*lst);
	if (!end_of_list)
	{
		*lst = new;
		return ;
	}
	end_of_list -> next = new;
}
//static void	print_list(t_list *lst)
//{
//	while (lst)
//	{
//		printf(" %s", (char *)lst -> content);
//		lst = lst -> next;
//	}
//	printf("  end of list");
//}
//int	main(void)
//{
//	t_list	*list = NULL;

//	ft_lstadd_back(&list, ft_lstnew(" WORLD"));
//	ft_lstadd_back(&list, ft_lstnew("!!"));
//	ft_lstadd_back(&list, ft_lstnew("YAY"));
//	print_list(list);
//	return (0);
//}
//1. get the last element of the list
//2. set the last->next variable to point to the new element
//3. if last is NULL, make the list pointer point to the new element
// If the list is empty, make new the first element
// Otherwise, add new to the end of the list
