/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:14:46 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/05 14:13:51 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	ft_toupper_basic(void)
{
	int	chr = 0;

	while (++chr <= 127)
		TEST_ASSERT_EQUAL_INT(toupper(chr), ft_toupper(chr));
}

void	ft_toupper_unsigned_char(void)
{
	int	chr = 375;

	TEST_ASSERT_EQUAL_INT(toupper(chr), ft_toupper(chr));
}

void	ft_toupper_negative(void)
{
	int	chr = -5;

	TEST_ASSERT_EQUAL_INT(toupper(chr), ft_toupper(chr));
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
	RUN_TEST(ft_toupper_basic);
	RUN_TEST(ft_toupper_unsigned_char);
	RUN_TEST(ft_toupper_negative);
	return (UNITY_END());
}
