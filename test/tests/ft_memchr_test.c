/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:14:46 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/02 10:10:51 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	ft_memchr_basic(void)
{
	char	*str = "Hello World";

	TEST_ASSERT_EQUAL_PTR(memchr(str, 'W', 11), ft_memchr(str, 'W', 11));
}

void	ft_memchr_not_found(void)
{
	char	*str = "Hello World";

	TEST_ASSERT_EQUAL_PTR(memchr(str, 'a', 11), ft_memchr(str, 'a', 11));
}

void	ft_memchr_not_found_len(void)
{
	char	*str = "Hello World";

	TEST_ASSERT_EQUAL_PTR(memchr(str, 'W', 6), ft_memchr(str, 'W', 6));
}

void	ft_memchr_unsigned_char(void)
{
	char	*str = "Hello World";

	TEST_ASSERT_EQUAL_PTR(memchr(str, 343, 11), ft_memchr(str, 343, 11));
}

void	ft_memchr_int_array(void)
{
	int	arr[] = { 1, 23, 54, 0, 74, 234, 13689 };

	TEST_ASSERT_EQUAL_PTR(memchr(arr, 234, 7 * sizeof(*arr)), ft_memchr(arr, 234, 7 * sizeof(*arr)));
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
	RUN_TEST(ft_memchr_basic);
	RUN_TEST(ft_memchr_not_found);
	RUN_TEST(ft_memchr_not_found_len);
	RUN_TEST(ft_memchr_unsigned_char);
	RUN_TEST(ft_memchr_int_array);
	return (UNITY_END());
}
