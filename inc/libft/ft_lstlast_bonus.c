/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:51:40 by tcakir-y          #+#    #+#             */
/*   Updated: 2024/12/09 20:42:18 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Returns the last node of the list.*/
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	if (temp == NULL)
		return (NULL);
	while (temp -> next != NULL)
	{
		temp = temp -> next;
	}
	return (temp);
}

//int	main(void)
//{
//	t_list	*list = ft_lstnew("!!");

//	ft_lstadd_front(&list, ft_lstnew(" world"));
//	ft_lstadd_front(&list, ft_lstnew("hello"));
//	printf("Last node is: %s", (char *)ft_lstlast(list) -> content);
//	return (0);
//}
