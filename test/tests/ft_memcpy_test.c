/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:14:46 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/01 12:08:53 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	ft_memcpy_basic(void)
{
	int		len = 6;
	char	*str = "Hello world and 42";
	char	ref[6];
	char	ret[6];

	TEST_ASSERT_EQUAL_MEMORY(memcpy(ref, str, len), ft_memcpy(ret, str, len), len);
}

void	ft_memcpy_right_overlap(void)
{
	int		len = 6;
	char	ref[] = "Hello world and 42";
	char	ret[] = "Hello world and 42";

	TEST_ASSERT_EQUAL_MEMORY(memcpy(ref + 2, ref, len), ft_memcpy(ret + 2, ret, len), len);
}

void	ft_memcpy_left_overlap(void)
{
	int		len = 6;
	char	ref[] = "Hello world and 42";
	char	ret[] = "Hello world and 42";

	TEST_ASSERT_EQUAL_MEMORY(memcpy(ref, ref + 2, len), ft_memcpy(ret, ret + 2, len), len);
}

void	ft_memcpy_int_array(void)
{
	int	len = 7;
	int	arr[] = { 1, 23, 54, 0, 74, 234, 13689 };
	int	ref[7];
	int	ret[7];

	TEST_ASSERT_EQUAL_MEMORY(memcpy(ref, arr, len * sizeof(*ref)), ft_memcpy(ret, arr, len * sizeof(*ret)), len * sizeof(*ref));
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
	RUN_TEST(ft_memcpy_basic);
	RUN_TEST(ft_memcpy_right_overlap);
	RUN_TEST(ft_memcpy_left_overlap);
	RUN_TEST(ft_memcpy_int_array);
	return (UNITY_END());
}
