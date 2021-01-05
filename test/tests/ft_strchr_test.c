/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:14:46 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/05 14:45:36 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	ft_strchr_basic(void)
{
	char	*str = "Hello World";
	int		chr = 'W';

	TEST_ASSERT_EQUAL_PTR(strchr(str, chr), ft_strchr(str, chr));
}

void	ft_strchr_not_found(void)
{
	char	*str = "Hello World";
	int		chr = 'X';

	TEST_ASSERT_EQUAL_PTR(strchr(str, chr), ft_strchr(str, chr));
}

void	ft_strchr_after_null(void)
{
	char	*str = "Hello \0World";
	int		chr = 'W';

	TEST_ASSERT_EQUAL_PTR(strchr(str, chr), ft_strchr(str, chr));
}

void	ft_strchr_unsigned_char(void)
{
	char	*str = "Hello World";
	int		chr = 343;

	TEST_ASSERT_EQUAL_PTR(strchr(str, chr), ft_strchr(str, chr));
}

void	ft_strchr_null_unsigned_char(void)
{
	char	*str = "Hello World";
	int		chr = 256;

	TEST_ASSERT_EQUAL_PTR(strchr(str, chr), ft_strchr(str, chr));
}

void	ft_strchr_invalid_char(void)
{
	char	*str = "Hello World";
	int		chr = -5;

	TEST_ASSERT_EQUAL_PTR(strchr(str, chr), ft_strchr(str, chr));
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
	RUN_TEST(ft_strchr_basic);
	RUN_TEST(ft_strchr_not_found);
	RUN_TEST(ft_strchr_after_null);
	RUN_TEST(ft_strchr_unsigned_char);
	RUN_TEST(ft_strchr_null_unsigned_char);
	RUN_TEST(ft_strchr_invalid_char);
	return (UNITY_END());
}
