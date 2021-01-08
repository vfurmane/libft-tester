/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:14:46 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/08 15:32:45 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

char	*ret;

void	ft_strtrim_basic(void)
{
	char	*str = "<>Hello World<>";
	char	*set = "<>";

	ret = ft_strtrim(str, set);
	TEST_ASSERT_EQUAL_STRING("Hello World", ret);
}

void	ft_strtrim_start(void)
{
	char	*str = "<>Hello World";
	char	*set = "<>";

	ret = ft_strtrim(str, set);
	TEST_ASSERT_EQUAL_STRING("Hello World", ret);
}

void	ft_strtrim_end(void)
{
	char	*str = "Hello World<>";
	char	*set = "<>";

	ret = ft_strtrim(str, set);
	TEST_ASSERT_EQUAL_STRING("Hello World", ret);
}

void	ft_strtrim_unordered(void)
{
	char	*str = "<<>>Hello World>><<";
	char	*set = "<>";

	ret = ft_strtrim(str, set);
	TEST_ASSERT_EQUAL_STRING("Hello World", ret);
}

void	ft_strtrim_empty_str(void)
{
	char	*str = "";
	char	*set = "<>";

	ret = ft_strtrim(str, set);
	TEST_ASSERT_EQUAL_STRING("", ret);
}

void	ft_strtrim_empty_set(void)
{
	char	*str = "Hello World";
	char	*set = "";

	ret = ft_strtrim(str, set);
	TEST_ASSERT_EQUAL_STRING("Hello World", ret);
}

void	ft_strtrim_in_string(void)
{
	char	*str = "Hello<>World";
	char	*set = "<>";

	ret = ft_strtrim(str, set);
	TEST_ASSERT_EQUAL_STRING("Hello<>World", ret);
}

void	ft_strtrim_partial(void)
{
	char	*str = "<Hello World>";
	char	*set = "<>";

	ret = ft_strtrim(str, set);
	TEST_ASSERT_EQUAL_STRING("Hello World", ret);
}

void	ft_strtrim_all_set(void)
{
	char	*str = "<>><><<>";
	char	*set = "<>";

	ret = ft_strtrim(str, set);
	TEST_ASSERT_EQUAL_STRING("", ret);
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
	RUN_TEST(ft_strtrim_basic);
	RUN_TEST(ft_strtrim_start);
	RUN_TEST(ft_strtrim_end);
	RUN_TEST(ft_strtrim_unordered);
	RUN_TEST(ft_strtrim_empty_str);
	RUN_TEST(ft_strtrim_empty_set);
	RUN_TEST(ft_strtrim_in_string);
	RUN_TEST(ft_strtrim_partial);
	RUN_TEST(ft_strtrim_all_set);
	return (UNITY_END());
}
