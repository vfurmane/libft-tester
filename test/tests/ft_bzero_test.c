/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:14:46 by vfurmane          #+#    #+#             */
/*   Updated: 2020/12/31 16:48:28 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	ft_bzero_basic(void)
{
	int		len = 5;
	char	ref[] = "Hello World";
	char	ret[] = "Hello World";

	bzero(ref, len);
	ft_bzero(ret, len);
	TEST_ASSERT_EQUAL_MEMORY(ref, ret, 12);
}

void	ft_bzero_int_array(void)
{
	int		len = 8;
	int		ref[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	int		ret[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

	bzero(ref, len);
	ft_bzero(ret, len);
	TEST_ASSERT_EQUAL_MEMORY(ref, ret, 10);
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
	RUN_TEST(ft_bzero_basic);
	RUN_TEST(ft_bzero_int_array);
	return (UNITY_END());
}
