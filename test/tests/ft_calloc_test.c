/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:14:46 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/11 13:14:36 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	*ref;
void	*ret;

void	ft_calloc_basic(void)
{
	int		len = 5;
	int		size = sizeof(int);

	ref = calloc(len, size);
	ret = ft_calloc(len, size);
	TEST_ASSERT_EQUAL_MEMORY(ref, ret, len * size);
}

void	ft_calloc_zero_len(void)
{
	int		len = 0;
	int		size = sizeof(int);

	ret = ft_calloc(len, size);
	TEST_ASSERT_NOT_NULL(ret);
}

void	ft_calloc_zero_size(void)
{
	int		len = 5;
	int		size = 0;

	ret = ft_calloc(len, size);
	TEST_ASSERT_NOT_NULL(ret);
}

void	ft_calloc_negative_len(void)
{
	int		len = -5;
	int		size = sizeof(int);

	ref = calloc(len, size);
	ret = ft_calloc(len, size);
	TEST_ASSERT_EQUAL_MEMORY(ref, ret, len * size);
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
	RUN_TEST(ft_calloc_basic);
	RUN_TEST(ft_calloc_zero_len);
	RUN_TEST(ft_calloc_zero_size);
	RUN_TEST(ft_calloc_negative_len);
	return (UNITY_END());
}
