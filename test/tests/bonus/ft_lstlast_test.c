/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:14:46 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/08 10:30:11 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

t_list	*ret;

void	ft_lstlast_basic(void)
{
	t_list	*ref;
	ret = ft_lstnew("Last content");
	ref = ret;
	ft_lstadd_front(&ret, ft_lstnew("Last - 1 content"));
	ft_lstadd_front(&ret, ft_lstnew("Last - 2 content"));
	ft_lstadd_front(&ret, ft_lstnew("Last - 3 content"));

	TEST_ASSERT_EQUAL_PTR(ref, ft_lstlast(ret));

	free(((ret->next)->next)->next);
	free((ret->next)->next);
	free(ret->next);
	free(ret);
}

void	ft_lstlast_null(void)
{
	TEST_ASSERT_EQUAL_INT(NULL, ft_lstlast(NULL));
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
	RUN_TEST(ft_lstlast_basic);
	RUN_TEST(ft_lstlast_null);
	return (UNITY_END());
}
