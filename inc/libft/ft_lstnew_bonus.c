/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:41:01 by tcakir-y          #+#    #+#             */
/*   Updated: 2024/12/09 20:38:30 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Allocates (with malloc(3)) and returns a new node.

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*result;

	result = (t_list *)malloc(sizeof(t_list));
	if (!result)
		return (NULL);
	result->content = content;
	result->next = NULL;
	return (result);
}

//static void	print_list(t_list list)
//{
//	while (list != NULL)
//	{
//		prinft(" %s ->", (char *)list -> content);
//		list = list -> next;
//	}
//	printf(" end");
//}
//int	main(void)
//{
//	t_list	*list = ft_lstnew("hello");
//	print_list(list);
//	return (0);
//}
