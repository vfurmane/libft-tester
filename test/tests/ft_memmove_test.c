/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:14:46 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/01 19:09:46 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	ft_memmove_basic(void)
{
	char	ref[] = "Hello world and 42";
	char	ret[] = "Hello world and 42";

	memmove(ref + 6, ref, 5);
	ft_memmove(ret + 6, ret, 5);
	TEST_ASSERT_EQUAL_MEMORY(ref, ret, 18);
}

void	ft_memmove_overlap(void)
{
	char	ref[] = "Hello world and 42";
	char	ret[] = "Hello world and 42";

	memmove(ref, ref + 6, 5);
	ft_memmove(ret, ret + 6, 5);
	TEST_ASSERT_EQUAL_MEMORY(ref, ret, 18);
}

void	ft_memmove_int_array(void)
{
	int	ref[] = { 1, 23, 54, 0, 74, 234, 13689, 2 };
	int	ret[] = { 1, 23, 54, 0, 74, 234, 13689, 3 };

	memmove(ref + 4, ref + 1, 3 * sizeof(*ref));
	ft_memmove(ret + 4, ret + 1, 3 * sizeof(*ret));
	TEST_ASSERT_EQUAL_MEMORY(ref, ret, 7 * sizeof(*ref));
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
	RUN_TEST(ft_memmove_basic);
	RUN_TEST(ft_memmove_overlap);
	RUN_TEST(ft_memmove_int_array);
	return (UNITY_END());
}
