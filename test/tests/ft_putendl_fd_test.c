/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:14:46 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/11 17:24:43 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	ft_putendl_fd_basic(void)
{
	char	*str = "Hello World";
	/* -------------------------------- */
	char	buffer[13];
	int		out_pipe[2];

	pipe(out_pipe);
	/* -------------------------------- */
	ft_putendl_fd(str, out_pipe[1]);
	/* -------------------------------- */
	read(out_pipe[0], buffer, 12);
	buffer[12] = '\0';
	close(out_pipe[0]);
	close(out_pipe[1]);
	TEST_ASSERT_EQUAL_STRING("Hello World\n", buffer);
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
	RUN_TEST(ft_putendl_fd_basic);
	return (UNITY_END());
}
