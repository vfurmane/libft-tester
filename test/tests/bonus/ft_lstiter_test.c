/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:14:46 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/09 12:52:14 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

t_list	*ret;
t_list	*ret2;

static void	ft_str_toupper(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		str[i] = ft_toupper(str[i]);
}

void	ft_lstiter_basic(void)
{
	char	str1[] = "Hello World";
	char	str2[] = "Hello World";

	ret = ft_lstnew(str1);
	ret2 = ft_lstnew(str2);
	ft_lstadd_back(&ret, ret2);
	ft_lstiter(ret, (void *)&ft_str_toupper);
	TEST_ASSERT_EQUAL_STRING("HELLO WORLD", ret->content);
	TEST_ASSERT_EQUAL_STRING("HELLO WORLD", (ret->next)->content);
}

/* -------------------------------------------------------------------------- */

void	setUp(void)
{
}

void	tearDown(void)
{
	free(ret);
}

int		main(void)
{
	UNITY_BEGIN();
	RUN_TEST(ft_lstiter_basic);
	return (UNITY_END());
}
