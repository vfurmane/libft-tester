/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:14:46 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/11 19:29:51 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	ft_strjoin_basic(void)
{
	char	*str1 = "Hello ";
	char	*str2 = "World";

	TEST_ASSERT_EQUAL_STRING("Hello World", ft_strjoin(str1, str2));
}

void	ft_strjoin_str1_empty(void)
{
	char	*str1 = "";
	char	*str2 = "World";

	TEST_ASSERT_EQUAL_STRING("World", ft_strjoin(str1, str2));
}

void	ft_strjoin_str2_empty(void)
{
	char	*str1 = "Hello";
	char	*str2 = "";

	TEST_ASSERT_EQUAL_STRING("Hello", ft_strjoin(str1, str2));
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
	RUN_TEST(ft_strjoin_basic);
	RUN_TEST(ft_strjoin_str1_empty);
	RUN_TEST(ft_strjoin_str2_empty);
	return (UNITY_END());
}
