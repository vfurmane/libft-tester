/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:14:46 by vfurmane          #+#    #+#             */
/*   Updated: 2020/12/30 19:06:54 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	ft_atoi_basic(void)
{
	char	*str = "42";

	TEST_ASSERT_EQUAL_INT(atoi(str), ft_atoi(str));
}

void	ft_atoi_negative(void)
{
	char	*str = "-42";

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
	RUN_TEST(ft_atoi_negative);
	return (UNITY_END());
}
