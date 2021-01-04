/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:14:46 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/04 20:54:16 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	ft_memcmp_basic(void)
{
	char	*str1 = "Hello World";
	char	*str2 = "Hello World";

	TEST_ASSERT_EQUAL_INT(memcmp(str1, str2, 11), ft_memcmp(str1, str2, 11));
}

void	ft_memcmp_different(void)
{
	char	*str1 = "Hello World";
	char	*str2 = "Hello world";

	TEST_ASSERT_EQUAL_INT(memcmp(str1, str2, 8), ft_memcmp(str1, str2, 8));
}

void	ft_memcmp_zero_length(void)
{
	char	*str1 = "Hello World";
	char	*str2 = "Hello World";

	TEST_ASSERT_EQUAL_INT(memcmp(str1, str2, 0), ft_memcmp(str1, str2, 0));
}

void	ft_memcmp_int_array(void)
{
	int	arr1[] = { 1, 23, 54, 0, 74, 234, 13689 };
	int	arr2[] = { 6, 23, 54, 0, 74, 234, 13689 };

	TEST_ASSERT_EQUAL_INT(memcmp(arr1, arr2, 7 * sizeof(*arr1)), ft_memcmp(arr1, arr2, 7 * sizeof(*arr2)));
}

void	ft_memcmp_invalid_len(void)
{
	int	arr1[] = { 1, 23, 54, 0, 74, 234, 13689 };
	int	arr2[] = { 1, 25, 54, 0, 74, 234, 13689 };

	TEST_ASSERT_EQUAL_INT(memcmp(arr1, arr2, 10), ft_memcmp(arr1, arr2, 10));
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
	RUN_TEST(ft_memcmp_basic);
	RUN_TEST(ft_memcmp_different);
	RUN_TEST(ft_memcmp_zero_length);
	RUN_TEST(ft_memcmp_int_array);
	RUN_TEST(ft_memcmp_invalid_len);
	return (UNITY_END());
}
