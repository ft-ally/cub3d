/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:31:06 by tcakir-y          #+#    #+#             */
/*   Updated: 2024/12/09 20:41:22 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Counts the number of nodes in a list.*/
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*temp;

	size = 0;
	temp = lst;
	while (temp != NULL)
	{
		size++;
		temp = temp -> next;
	}
	return (size);
}

//static void	print_list(t_list *list)
//{
//	while (list != NULL)
//	{
//		printf("%s -> ", (char *)list -> content);
//		list = list -> next;
//	}
//}
//int main(void)
//{
//	t_list *list = ft_lstnew(" !!");
//	ft_lstadd_front(&list, ft_lstnew(" world"));
//	ft_lstadd_front(&list, ft_lstnew("hello"));
//	printf("size is %d\n", ft_lstsize(list));
//	print_list(list);
//	return (0);
//}
