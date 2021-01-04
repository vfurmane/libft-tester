/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:14:46 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/04 14:29:09 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	ft_memccpy_basic(void)
{
	int		len = 19;
	char	*str = "Hello world! and 42";
	char	ref[19];
	char	ret[19];

	bzero(ref, len);
	bzero(ret, len);
	TEST_ASSERT_EQUAL_MEMORY(memccpy(ref, str, '!', len), ft_memccpy(ret, str, '!', len), 1);
	TEST_ASSERT_EQUAL_MEMORY(ref, ret, len);
}

void	ft_memccpy_no_end(void)
{
	int		len = 18;
	char	*str = "Hello world and 42";
	char	ref[18];
	char	ret[18];

	bzero(ref, len);
	bzero(ret, len);
	TEST_ASSERT_EQUAL_MEMORY(memccpy(ref, str, '!', len), ft_memccpy(ret, str, '!', len), 1);
	TEST_ASSERT_EQUAL_MEMORY(ref, ret, len);
}

void	ft_memccpy_int_array(void)
{
	int	len = 7;
	int	arr[] = { 1, 23, 54, 0, 74, 234, 13689 };
	int	ref[7];
	int	ret[7];

	bzero(ref, len * sizeof(*arr));
	bzero(ret, len * sizeof(*arr));
	TEST_ASSERT_EQUAL_MEMORY(memccpy(ref, arr, 74, len * sizeof(*ref)), ft_memccpy(ret, arr, 74, len * sizeof(*ret)), sizeof(*ref));
	TEST_ASSERT_EQUAL_MEMORY(ref, ret, len * sizeof(*ref));
}

void	ft_memccpy_invalid_byte_size(void)
{
	int	len = 7;
	int	arr[] = { 1, 23, 54, 0, 74, 234, 13689 };
	int	ref[7];
	int	ret[7];

	bzero(ref, len * sizeof(*arr));
	bzero(ret, len * sizeof(*arr));
	TEST_ASSERT_EQUAL_MEMORY(memccpy(ref, arr, 74, 6), ft_memccpy(ret, arr, 74, 6), sizeof(*ref));
	TEST_ASSERT_EQUAL_MEMORY(ref, ret, len * sizeof(*ref));
}

void	ft_memccpy_char_overflow(void)
{
	int		len = 18;
	char	*str = "Hello world and 42";
	char	ref[18];
	char	ret[18];

	bzero(ref, len);
	bzero(ret, len);
	TEST_ASSERT_EQUAL_MEMORY(memccpy(ref, str, 353, len), ft_memccpy(ret, str, 353, len), 1);
	TEST_ASSERT_EQUAL_MEMORY(ref, ret, len);
}

/* Doesn't work on MacOS */

void	ft_memccpy_negative_len(void)
{
	int		len = -3;
	char	*str = "Hello world! and 42";
	char	ref[19];
	char	ret[19];

	bzero(ref, 19);
	bzero(ret, 19);
	TEST_ASSERT_EQUAL_MEMORY(memccpy(ref, str, '!', len), ft_memccpy(ret, str, '!', len), 1);
	TEST_ASSERT_EQUAL_MEMORY(ref, ret, 19);
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
	RUN_TEST(ft_memccpy_basic);
	RUN_TEST(ft_memccpy_no_end);
	RUN_TEST(ft_memccpy_int_array);
	RUN_TEST(ft_memccpy_invalid_byte_size);
	RUN_TEST(ft_memccpy_char_overflow);
	// RUN_TEST(ft_memccpy_negative_len);
	return (UNITY_END());
}
