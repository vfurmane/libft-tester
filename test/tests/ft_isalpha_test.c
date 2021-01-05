/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:14:46 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/05 12:05:10 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	ft_isalpha_basic(void)
{
	int	chr = 'A' - 1;

	while (++chr <= 'Z')
		TEST_ASSERT_EQUAL_INT(isalpha(chr), ft_isalpha(chr));
	chr = 'a' - 1;
	while (++chr <= 'z')
		TEST_ASSERT_EQUAL_INT(isalpha(chr), ft_isalpha(chr));
}

void	ft_isalpha_not_alpha(void)
{
	int	chr = '.';

	TEST_ASSERT_EQUAL_INT(isalpha(chr), ft_isalpha(chr));
}

void	ft_isalpha_unsigned_char(void)
{
	int	chr = 343;

	TEST_ASSERT_EQUAL_INT(isalpha(chr), ft_isalpha(chr));
}

void	ft_isalpha_negative(void)
{
	int	chr = -5;

	TEST_ASSERT_EQUAL_INT(isalpha(chr), ft_isalpha(chr));
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
	RUN_TEST(ft_isalpha_basic);
	RUN_TEST(ft_isalpha_not_alpha);
	RUN_TEST(ft_isalpha_unsigned_char);
	RUN_TEST(ft_isalpha_negative);
	return (UNITY_END());
}
