/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:14:46 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/06 10:22:23 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	ft_strlcpy_basic(void)
{
	char	*str = "Hello World";
	char	ret[12];
	char	ref[12];

	bzero(ref, 12);
	bzero(ret, 12);
	TEST_ASSERT_EQUAL_INT(strlcpy(ref, str, 12), ft_strlcpy(ret, str, 12));
	TEST_ASSERT_EQUAL_MEMORY(ref, ret, 12);
}

void	ft_strlcpy_incomplete_str(void)
{
	char	*str = "Hello World";
	char	ret[6];
	char	ref[6];

	bzero(ref, 6);
	bzero(ret, 6);
	TEST_ASSERT_EQUAL_INT(strlcpy(ref, str, 6), ft_strlcpy(ret, str, 6));
	TEST_ASSERT_EQUAL_MEMORY(ref, ret, 6);
}

void	ft_strlcpy_zero_len(void)
{
	char	*str = "Hello World";
	char	ret[12];
	char	ref[12];

	bzero(ref, 12);
	bzero(ret, 12);
	TEST_ASSERT_EQUAL_INT(strlcpy(ref, str, 0), ft_strlcpy(ret, str, 0));
	TEST_ASSERT_EQUAL_MEMORY(ref, ret, 12);
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
	RUN_TEST(ft_strlcpy_basic);
	RUN_TEST(ft_strlcpy_incomplete_str);
	RUN_TEST(ft_strlcpy_zero_len);
	return (UNITY_END());
}
