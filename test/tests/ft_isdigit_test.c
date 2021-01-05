/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:14:46 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/05 12:19:55 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	ft_isdigit_basic(void)
{
	int	chr = '0' - 1;

	while (++chr <= '9')
		TEST_ASSERT_EQUAL_INT(isdigit(chr), ft_isdigit(chr));
}

void	ft_isdigit_not_digit(void)
{
	int	chr = '.';

	TEST_ASSERT_EQUAL_INT(isdigit(chr), ft_isdigit(chr));
}

void	ft_isdigit_unsigned_char(void)
{
	int	chr = 306;

	TEST_ASSERT_EQUAL_INT(isdigit(chr), ft_isdigit(chr));
}

void	ft_isdigit_negative(void)
{
	int	chr = -5;

	TEST_ASSERT_EQUAL_INT(isdigit(chr), ft_isdigit(chr));
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
	RUN_TEST(ft_isdigit_basic);
	RUN_TEST(ft_isdigit_not_digit);
	RUN_TEST(ft_isdigit_unsigned_char);
	RUN_TEST(ft_isdigit_negative);
	return (UNITY_END());
}
