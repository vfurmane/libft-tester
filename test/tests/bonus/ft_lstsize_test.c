/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:14:46 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/07 17:54:04 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

t_list	*ret;

void	ft_lstsize_basic(void)
{
	ret = ft_lstnew("Ref content");
	ft_lstadd_front(&ret, ft_lstnew("Ref content"));
	ft_lstadd_front(&ret, ft_lstnew("Ref content"));
	ft_lstadd_front(&ret, ft_lstnew("Ref content"));

	TEST_ASSERT_EQUAL_INT(4, ft_lstsize(ret));

	free(((ret->next)->next)->next);
	free((ret->next)->next);
	free(ret->next);
	free(ret);
}

void	ft_lstsize_null(void)
{
	TEST_ASSERT_EQUAL_INT(0, ft_lstsize(NULL));
}

/* -------------------------------------------------------------------------- */

void	setUp(void)
{
}

void	tearDown(void)
{
}

int		main(void)
{
	UNITY_BEGIN();
	RUN_TEST(ft_lstsize_basic);
	RUN_TEST(ft_lstsize_null);
	return (UNITY_END());
}
