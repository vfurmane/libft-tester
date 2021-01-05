/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:14:46 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/05 13:59:32 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	ft_isprint_basic(void)
{
	int	chr = 0;

	while (++chr <= 127)
		TEST_ASSERT_EQUAL_INT(isprint(chr), ft_isprint(chr));
}

void	ft_isprint_not_print(void)
{
	int	chr = 132;

	TEST_ASSERT_EQUAL_INT(isprint(chr), ft_isprint(chr));
}

void	ft_isprint_unsigned_char(void)
{
	int	chr = 343;

	TEST_ASSERT_EQUAL_INT(isprint(chr), ft_isprint(chr));
}

void	ft_isprint_negative(void)
{
	int	chr = -5;

	TEST_ASSERT_EQUAL_INT(isprint(chr), ft_isprint(chr));
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
	RUN_TEST(ft_isprint_basic);
	RUN_TEST(ft_isprint_not_print);
	RUN_TEST(ft_isprint_unsigned_char);
	RUN_TEST(ft_isprint_negative);
	return (UNITY_END());
}
