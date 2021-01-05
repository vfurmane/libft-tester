/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:14:46 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/05 14:22:26 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	ft_tolower_basic(void)
{
	int	chr = 0;

	while (++chr <= 127)
		TEST_ASSERT_EQUAL_INT(tolower(chr), ft_tolower(chr));
}

void	ft_tolower_unsigned_char(void)
{
	int	chr = 343;

	TEST_ASSERT_EQUAL_INT(tolower(chr), ft_tolower(chr));
}

void	ft_tolower_negative(void)
{
	int	chr = -5;

	TEST_ASSERT_EQUAL_INT(tolower(chr), ft_tolower(chr));
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
	RUN_TEST(ft_tolower_basic);
	RUN_TEST(ft_tolower_unsigned_char);
	RUN_TEST(ft_tolower_negative);
	return (UNITY_END());
}
