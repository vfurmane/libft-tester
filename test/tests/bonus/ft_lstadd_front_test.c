/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:14:46 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/07 12:44:13 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

t_list	*ret;
t_list	*new_lst;
t_list	*initial_lst;

void	ft_lstadd_front_basic(void)
{
	char	*str = "Hello World";

	new_lst = ft_lstnew(str);
	ft_lstadd_front(&ret, new_lst);
	TEST_ASSERT_EQUAL_STRING(str, ret->content);
	TEST_ASSERT_EQUAL_PTR(initial_lst, ret->next);
}

void	ft_lstadd_front_non_ptr_content(void)
{
	int	nbr = 42;

	new_lst = ft_lstnew(&nbr);
	ft_lstadd_front(&ret, new_lst);
	TEST_ASSERT_EQUAL_INT(nbr, *((int*)ret->content));
	TEST_ASSERT_EQUAL_PTR(initial_lst, ret->next);
}

/* -------------------------------------------------------------------------- */

void	setUp(void)
{
	ret = ft_lstnew("Ref content");
	initial_lst = ret;
}

void	tearDown(void)
{
	free(ret->next);
	free(ret);
}

int		main(void)
{
	UNITY_BEGIN();
	RUN_TEST(ft_lstadd_front_basic);
	RUN_TEST(ft_lstadd_front_non_ptr_content);
	return (UNITY_END());
}
