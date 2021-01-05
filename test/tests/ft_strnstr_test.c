/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:14:46 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/06 10:49:15 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	ft_strnstr_basic(void)
{
	char	*str = "Hello World";
	char	*find = "lo W";
	size_t	len = 11;

	TEST_ASSERT_EQUAL_PTR(strnstr(str, find, len), ft_strnstr(str, find, len));
}

void	ft_strnstr_almost_found(void)
{
	char	*str = "Hello World";
	char	*find = "elo";
	size_t	len = 11;

	TEST_ASSERT_EQUAL_PTR(strnstr(str, find, len), ft_strnstr(str, find, len));
}

void	ft_strnstr_empty_str(void)
{
	char	*str = "Hello World";
	char	*find = "";
	size_t	len = 11;

	TEST_ASSERT_EQUAL_PTR(strnstr(str, find, len), ft_strnstr(str, find, len));
}

void	ft_strnstr_after_len(void)
{
	char	*str = "Hello World";
	char	*find = "Wo";
	size_t	len = 6;

	TEST_ASSERT_EQUAL_PTR(strnstr(str, find, len), ft_strnstr(str, find, len));
}

void	ft_strnstr_overlap_len(void)
{
	char	*str = "Hello World";
	char	*find = "Wo";
	size_t	len = 7;

	TEST_ASSERT_EQUAL_PTR(strnstr(str, find, len), ft_strnstr(str, find, len));
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
	RUN_TEST(ft_strnstr_basic);
	RUN_TEST(ft_strnstr_almost_found);
	RUN_TEST(ft_strnstr_empty_str);
	RUN_TEST(ft_strnstr_after_len);
	RUN_TEST(ft_strnstr_overlap_len);
	return (UNITY_END());
}
