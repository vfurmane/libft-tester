/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:14:46 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/08 14:31:08 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

char	*ref[5] = { "Hello", "World", "and", "42", NULL };
char	*ref2[2] = { "Hello World and 42", NULL };
char	*ref3[13] = { "lorem", "ipsum", "dolor", "sit", "amet,", "consectetur", "adipiscing", "elit.", "Sed", "non", "risus.", "Suspendisse", NULL };
char	**ret;

int		ft_arrlen(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	ft_split_basic(void)
{
	char	*str = "Hello World and 42";
	char	sep = ' ';

	ret = ft_split(str, sep);
	TEST_ASSERT_EQUAL_STRING_ARRAY(ref, ret, ft_arrlen(ret) + 1);
}

void	ft_split_long_sep(void)
{
	char	*str = "        Hello    World     and       42          ";
	char	sep = ' ';

	ret = ft_split(str, sep);
	TEST_ASSERT_EQUAL_STRING_ARRAY(ref, ret, ft_arrlen(ret) + 1);
}

void	ft_split_no_sep(void)
{
	char	*str = "Hello World and 42";
	char	sep = 'y';

	ret = ft_split(str, sep);
	TEST_ASSERT_EQUAL_STRING_ARRAY(ref2, ret, ft_arrlen(ret) + 1);
}

void	ft_split_zero_sep(void)
{
	char	*str = "Hello World and 42";
	char	sep = '\0';

	ret = ft_split(str, sep);
	TEST_ASSERT_EQUAL_STRING_ARRAY(ref2, ret, ft_arrlen(ret) + 1);
}

void	ft_split_test(void)
{
	char	*str = "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse";
	char	sep = ' ';

	ret = ft_split(str, sep);
	TEST_ASSERT_EQUAL_STRING_ARRAY(ref3, ret, ft_arrlen(ret) + 1);
}

/* -------------------------------------------------------------------------- */

void	setUp(void)
{
}

void	tearDown(void)
{
	/*
	int	i;

	i = 0;
	while (ret[i])
	{
		free(ret[i]);
	}
	free(ret);
	*/
}

int		main(void)
{
	UNITY_BEGIN();
	RUN_TEST(ft_split_basic);
	RUN_TEST(ft_split_long_sep);
	RUN_TEST(ft_split_no_sep);
	RUN_TEST(ft_split_zero_sep);
	RUN_TEST(ft_split_test);
	return (UNITY_END());
}
