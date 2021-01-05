/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:14:46 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/06 10:35:08 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	ft_strlcat_basic(void)
{
	char	*str = "World";
	char	ret[12] = "Hello ";
	char	ref[12] = "Hello ";

	TEST_ASSERT_EQUAL_INT(strlcat(ref, str, 12), ft_strlcat(ret, str, 12));
	TEST_ASSERT_EQUAL_MEMORY(ref, ret, 12);
}

void	ft_strlcat_overflow(void)
{
	char	*str = "Hello World";
	char	ret[12] = "Salut";
	char	ref[12] = "Salut";

	TEST_ASSERT_EQUAL_INT(strlcat(ref, str, 10), ft_strlcat(ret, str, 10));
	TEST_ASSERT_EQUAL_MEMORY(ref, ret, 12);
}

void	ft_strlcat_no_copy(void)
{
	char	*str = "Hello World";
	char	ret[12] = "Salut";
	char	ref[12] = "Salut";

	TEST_ASSERT_EQUAL_INT(strlcat(ref, str, 2), ft_strlcat(ret, str, 2));
	TEST_ASSERT_EQUAL_MEMORY(ref, ret, 12);
}

void	ft_strlcat_short_len(void)
{
	char	*str = "Hello World";
	char	ret[12] = "Salut";
	char	ref[12] = "Salut";

	TEST_ASSERT_EQUAL_INT(strlcat(ref, str, 6), ft_strlcat(ret, str, 6));
	TEST_ASSERT_EQUAL_MEMORY(ref, ret, 12);
}

void	ft_strlcat_zero_len(void)
{
	char	*str = "Hello World";
	char	ret[12] = "Salut";
	char	ref[12] = "Salut";

	TEST_ASSERT_EQUAL_INT(strlcat(ref, str, 0), ft_strlcat(ret, str, 0));
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
	RUN_TEST(ft_strlcat_basic);
	RUN_TEST(ft_strlcat_overflow);
	RUN_TEST(ft_strlcat_no_copy);
	RUN_TEST(ft_strlcat_short_len);
	RUN_TEST(ft_strlcat_zero_len);
	return (UNITY_END());
}
