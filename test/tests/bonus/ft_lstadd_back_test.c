/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:14:46 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/09 11:43:13 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

t_list	*ret;
t_list	*new_lst;
t_list	*new_lst2;
t_list	*initial_lst;

void	ft_lstadd_back_basic(void)
{
	char	*str = "Hello World";

	ret = ft_lstnew("Ref content");
	initial_lst = ret;
	new_lst = ft_lstnew(str);
	ft_lstadd_back(&ret, new_lst);
	TEST_ASSERT_EQUAL_STRING(str, ft_lstlast(ret)->content);
	TEST_ASSERT_EQUAL_PTR(initial_lst->next, ft_lstlast(ret));
}

void	ft_lstadd_back_null_ptr(void)
{
	char	*str = "Hello World";

	new_lst = ft_lstnew(str);
	new_lst2 = ft_lstnew(str);
	ret = NULL;
	ft_lstadd_back(&ret, new_lst);
	ft_lstadd_back(&ret, new_lst2);
	TEST_ASSERT_EQUAL_STRING(str, ft_lstlast(ret)->content);
	TEST_ASSERT_EQUAL_PTR(initial_lst->next, ft_lstlast(ret));
}

void	ft_lstadd_back_non_ptr_content(void)
{
	int	nbr = 42;

	ret = ft_lstnew("Ref content");
	initial_lst = ret;
	new_lst = ft_lstnew(&nbr);
	ft_lstadd_back(&ret, new_lst);
	TEST_ASSERT_EQUAL_INT(nbr, *((int*)ft_lstlast(ret)->content));
	TEST_ASSERT_EQUAL_PTR(initial_lst->next, ft_lstlast(ret));
}

/* -------------------------------------------------------------------------- */

void	setUp(void)
{
}

void	tearDown(void)
{
	free(ret->next);
	free(ret);
}

int		main(void)
{
	UNITY_BEGIN();
	RUN_TEST(ft_lstadd_back_basic);
	RUN_TEST(ft_lstadd_back_null_ptr);
	RUN_TEST(ft_lstadd_back_non_ptr_content);
	return (UNITY_END());
}
