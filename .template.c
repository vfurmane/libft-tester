/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .template.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:14:46 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/05 11:22:36 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	ft_name_basic(void)
{
	char	*str = "This string is 33 characters long";

	TEST_ASSERT_EQUAL_INT(name(str), ft_name(str));
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
	RUN_TEST(ft_name_basic);
	return (UNITY_END());
}
