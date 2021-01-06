/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:14:46 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/06 11:17:59 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

char	*ref;
char	*ret;

void	ft_strdup_basic(void)
{
	char	*str = "Hello World";

	ref = strdup(str);
	ret = ft_strdup(str);
	TEST_ASSERT_EQUAL_STRING(ret, ret);
}

/* -------------------------------------------------------------------------- */

void	setUp(void)
{
}

void	tearDown(void)
{
	free(ref);
	free(ret);
}

int		main(void)
{
	UNITY_BEGIN();
	RUN_TEST(ft_strdup_basic);
	return (UNITY_END());
}
