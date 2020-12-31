/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:14:46 by vfurmane          #+#    #+#             */
/*   Updated: 2020/12/31 16:38:11 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	ft_memset_basic(void)
{
	char	chr = '-';
	int		len = 5;
	char	ref[] = "Hello World";
	char	ret[] = "Hello World";

	TEST_ASSERT_EQUAL_MEMORY(memset(ref, chr, len), ft_memset(ret, chr, len), 12);
}

void	ft_memset_invalid_char(void)
{
	char	chr = -3;
	int		len = 5;
	char	ref[] = "Hello World";
	char	ret[] = "Hello World";

	TEST_ASSERT_EQUAL_MEMORY(memset(ref, chr, len), ft_memset(ret, chr, len), 12);
}

void	ft_memset_int_array(void)
{
	char	chr = 4;
	int		len = 8;
	int		ref[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int		ret[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	TEST_ASSERT_EQUAL_MEMORY(memset(ref, chr, len), ft_memset(ret, chr, len), 10);
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
	RUN_TEST(ft_memset_basic);
	RUN_TEST(ft_memset_invalid_char);
	RUN_TEST(ft_memset_int_array);
	return (UNITY_END());
}
