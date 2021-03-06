/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:14:46 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/11 19:19:09 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

char	*ret;

void	ft_substr_basic(void)
{
	char	*str = "Hello World and 42";

	ret = ft_substr(str, 6, 5);
	TEST_ASSERT_EQUAL_STRING("World", ret);
}

void	ft_substr_zero_len(void)
{
	char	*str = "Hello World and 42";

	ret = ft_substr(str, 6, 0);
	TEST_ASSERT_EQUAL_STRING("", ret);
}

void	ft_substr_too_long_len(void)
{
	char	*str = "Hello World and 42";

	ret = ft_substr(str, 16, 5);
	TEST_ASSERT_EQUAL_STRING("42", ret);
}

void	ft_substr_start_after_end(void)
{
	char	*str = "Hello World";

	ret = ft_substr(str, 12, 5);
	TEST_ASSERT_EQUAL_STRING("", ret);
}

/* -------------------------------------------------------------------------- */

void	setUp(void)
{
}

void	tearDown(void)
{
	free(ret);
}

int		main(void)
{
	UNITY_BEGIN();
	RUN_TEST(ft_substr_basic);
	RUN_TEST(ft_substr_zero_len);
	RUN_TEST(ft_substr_too_long_len);
	RUN_TEST(ft_substr_start_after_end);
	return (UNITY_END());
}
