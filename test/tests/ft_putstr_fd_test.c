/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:14:46 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/11 17:36:19 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	ft_putstr_fd_basic(void)
{
	char	*str = "Hello World";
	/* -------------------------------- */
	char	buffer[12];
	int		out_pipe[2];

	pipe(out_pipe);
	/* -------------------------------- */
	ft_putendl_fd(str, out_pipe[1]);
	/* -------------------------------- */
	read(out_pipe[0], buffer, 11);
	buffer[11] = '\0';
	close(out_pipe[0]);
	close(out_pipe[1]);
	TEST_ASSERT_EQUAL_STRING("Hello World", buffer);
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
	RUN_TEST(ft_putstr_fd_basic);
	return (UNITY_END());
}
