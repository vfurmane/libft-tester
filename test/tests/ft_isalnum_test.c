/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:14:46 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/05 12:42:44 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	ft_isalnum_basic(void)
{
	int	chr = 'A' - 1;

	while (++chr <= 'Z')
		TEST_ASSERT_EQUAL_INT(isalnum(chr), ft_isalnum(chr));
	chr = 'a' - 1;
	while (++chr <= 'z')
		TEST_ASSERT_EQUAL_INT(isalnum(chr), ft_isalnum(chr));
	chr = '0' - 1;
	while (++chr <= '9')
		TEST_ASSERT_EQUAL_INT(isalnum(chr), ft_isalnum(chr));
}

void	ft_isalnum_not_alnum(void)
{
	int	chr = '.';

	TEST_ASSERT_EQUAL_INT(isalnum(chr), ft_isalnum(chr));
}

void	ft_isalnum_unsigned_char(void)
{
	int	chr = 343;

	TEST_ASSERT_EQUAL_INT(isalnum(chr), ft_isalnum(chr));
}

void	ft_isalnum_negative(void)
{
	int	chr = -5;

	TEST_ASSERT_EQUAL_INT(isalnum(chr), ft_isalnum(chr));
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
	RUN_TEST(ft_isalnum_basic);
	RUN_TEST(ft_isalnum_not_alnum);
	RUN_TEST(ft_isalnum_unsigned_char);
	RUN_TEST(ft_isalnum_negative);
	return (UNITY_END());
}
