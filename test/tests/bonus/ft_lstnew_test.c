/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:14:46 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/07 12:12:29 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

t_list	*ret;

void	ft_lstnew_basic(void)
{
	char	*str = "Hello World";

	ret = ft_lstnew(str);
	TEST_ASSERT_EQUAL_STRING(str, ret->content);
	TEST_ASSERT_EQUAL_PTR(NULL, ret->next);
}

void	ft_lstnew_non_ptr_content(void)
{
	int	nbr = 42;

	ret = ft_lstnew(&nbr);
	TEST_ASSERT_EQUAL_INT(nbr, *((int*)ret->content));
	TEST_ASSERT_EQUAL_PTR(NULL, ret->next);
}

/* -------------------------------------------------------------------------- */

void	setUp(void)
{
}

void	tearDown(void)
{
	free(ret);
}

int		main(void)
{
	UNITY_BEGIN();
	RUN_TEST(ft_lstnew_basic);
	RUN_TEST(ft_lstnew_non_ptr_content);
	return (UNITY_END());
}
