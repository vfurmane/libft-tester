/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:14:46 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/08 12:43:33 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	ft_itoa_basic(void)
{
	int	nbr = 42;

	TEST_ASSERT_EQUAL_STRING("42", ft_itoa(nbr));
}

void	ft_itoa_negative(void)
{
	int	nbr = -42;

	TEST_ASSERT_EQUAL_STRING("-42", ft_itoa(nbr));
}

void	ft_itoa_big_number(void)
{
	int	nbr = 2147483647;

	TEST_ASSERT_EQUAL_STRING("2147483647", ft_itoa(nbr));
}

void	ft_itoa_negative_overflow(void)
{
	int	nbr = -2147483648LL;

	TEST_ASSERT_EQUAL_STRING("-2147483648", ft_itoa(nbr));
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
	RUN_TEST(ft_itoa_basic);
	RUN_TEST(ft_itoa_negative);
	RUN_TEST(ft_itoa_big_number);
	RUN_TEST(ft_itoa_negative_overflow);
	return (UNITY_END());
}
