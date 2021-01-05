/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:14:46 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/05 15:17:10 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	ft_strncmp_basic(void)
{
	char	*str1 = "Hello World";
	char	*str2 = "Hello World";

	TEST_ASSERT_EQUAL_INT(strncmp(str1, str2, 11), ft_strncmp(str1, str2, 11));
}

void	ft_strncmp_different(void)
{
	char	*str1 = "Hello World";
	char	*str2 = "Hello world";

	TEST_ASSERT_EQUAL_INT(strncmp(str1, str2, 8), ft_strncmp(str1, str2, 8));
}

void	ft_strncmp_after_len(void)
{
	char	*str1 = "Hello World";
	char	*str2 = "Hello world";

	TEST_ASSERT_EQUAL_INT(strncmp(str1, str2, 6), ft_strncmp(str1, str2, 6));
}

void	ft_strncmp_zero_length(void)
{
	char	*str1 = "Hello World";
	char	*str2 = "Hello World";

	TEST_ASSERT_EQUAL_INT(strncmp(str1, str2, 0), ft_strncmp(str1, str2, 0));
}

void	ft_strncmp_at_null(void)
{
	char	*str1 = "Hello World ";
	char	*str2 = "Hello\0 world";

	TEST_ASSERT_EQUAL_INT(strncmp(str1, str2, 12), ft_strncmp(str1, str2, 12));
}

void	ft_strncmp_after_null(void)
{
	char	*str1 = "Hello\0 World";
	char	*str2 = "Hello\0 world";

	TEST_ASSERT_EQUAL_INT(strncmp(str1, str2, 12), ft_strncmp(str1, str2, 12));
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
	RUN_TEST(ft_strncmp_basic);
	RUN_TEST(ft_strncmp_different);
	RUN_TEST(ft_strncmp_after_len);
	RUN_TEST(ft_strncmp_zero_length);
	RUN_TEST(ft_strncmp_at_null);
	RUN_TEST(ft_strncmp_after_null);
	return (UNITY_END());
}
