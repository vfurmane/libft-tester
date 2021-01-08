/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:14:46 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/08 11:58:09 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	ft_atoi_basic(void)
{
	char	*str = "42";

	TEST_ASSERT_EQUAL_INT(atoi(str), ft_atoi(str));
}

void	ft_atoi_positive(void)
{
	char	*str = "+42";

	TEST_ASSERT_EQUAL_INT(atoi(str), ft_atoi(str));
}

void	ft_atoi_negative(void)
{
	char	*str = "-42";

	TEST_ASSERT_EQUAL_INT(atoi(str), ft_atoi(str));
}

void	ft_atoi_invalid_negative(void)
{
	char	*str = "--42";

	TEST_ASSERT_EQUAL_INT(atoi(str), ft_atoi(str));
}

void	ft_atoi_whitespaces(void)
{
	char	*str = " \t\r\n\f\v42";

	TEST_ASSERT_EQUAL_INT(atoi(str), ft_atoi(str));
}

void	ft_atoi_invalid_number(void)
{
	char	*str = "42a24";

	TEST_ASSERT_EQUAL_INT(atoi(str), ft_atoi(str));
}

void	ft_atoi_int_limit(void)
{
	char	*str = "3000000000";

	TEST_ASSERT_EQUAL_INT(atoi(str), ft_atoi(str));
}

void	ft_atoi_plus_minus(void)
{
	char	*str = "+-42";

	TEST_ASSERT_EQUAL_INT(atoi(str), ft_atoi(str));
}

void	ft_atoi_plus_plus(void)
{
	char	*str = "++42";

	TEST_ASSERT_EQUAL_INT(atoi(str), ft_atoi(str));
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
	RUN_TEST(ft_atoi_basic);
	RUN_TEST(ft_atoi_positive);
	RUN_TEST(ft_atoi_negative);
	RUN_TEST(ft_atoi_invalid_negative);
	RUN_TEST(ft_atoi_whitespaces);
	RUN_TEST(ft_atoi_invalid_number);
	RUN_TEST(ft_atoi_int_limit);
	RUN_TEST(ft_atoi_plus_minus);
	RUN_TEST(ft_atoi_plus_plus);
	return (UNITY_END());
}
