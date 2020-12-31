/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:14:46 by vfurmane          #+#    #+#             */
/*   Updated: 2020/12/31 15:51:28 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	ft_strlen_basic(void)
{
	char	*str = "This string is 33 characters long";

	TEST_ASSERT_EQUAL_INT(strlen(str), ft_strlen(str));
}

void	ft_strlen_containing_0(void)
{
	char	*str = "This string\0 is 61 characters long, but stops at character 11";

	TEST_ASSERT_EQUAL_INT(strlen(str), ft_strlen(str));
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
	RUN_TEST(ft_strlen_basic);
	RUN_TEST(ft_strlen_containing_0);
	return (UNITY_END());
}
