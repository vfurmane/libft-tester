/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:14:46 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/05 13:50:17 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	ft_isascii_basic(void)
{
	int	chr = 0;

	while (++chr <= 127)
		TEST_ASSERT_EQUAL_INT(isascii(chr), ft_isascii(chr));
}

void	ft_isascii_not_ascii(void)
{
	int	chr = 132;

	TEST_ASSERT_EQUAL_INT(isascii(chr), ft_isascii(chr));
}

void	ft_isascii_unsigned_char(void)
{
	int	chr = 343;

	TEST_ASSERT_EQUAL_INT(isascii(chr), ft_isascii(chr));
}

void	ft_isascii_negative(void)
{
	int	chr = -5;

	TEST_ASSERT_EQUAL_INT(isascii(chr), ft_isascii(chr));
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
	RUN_TEST(ft_isascii_basic);
	RUN_TEST(ft_isascii_not_ascii);
	RUN_TEST(ft_isascii_unsigned_char);
	RUN_TEST(ft_isascii_negative);
	return (UNITY_END());
}
