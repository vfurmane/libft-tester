/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:14:46 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/11 17:11:21 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	ft_putchar_fd_basic(void)
{
	char	chr = 'W';
	/* -------------------------------- */
	char	buffer[2];
	int		out_pipe[2];

	pipe(out_pipe);
	/* -------------------------------- */
	ft_putchar_fd(chr, out_pipe[1]);
	/* -------------------------------- */
	read(out_pipe[0], buffer, 1);
	buffer[1] = '\0';
	close(out_pipe[0]);
	close(out_pipe[1]);
	TEST_ASSERT_EQUAL_STRING("W", buffer);
}

void	ft_putchar_fd_unsigned_char(void)
{
	int		chr = 343;
	/* -------------------------------- */
	char	buffer[2];
	int		out_pipe[2];

	pipe(out_pipe);
	/* -------------------------------- */
	ft_putchar_fd(chr, out_pipe[1]);
	/* -------------------------------- */
	read(out_pipe[0], buffer, 1);
	buffer[1] = '\0';
	close(out_pipe[0]);
	close(out_pipe[1]);
	TEST_ASSERT_EQUAL_STRING("W", buffer);
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
	RUN_TEST(ft_putchar_fd_basic);
	RUN_TEST(ft_putchar_fd_unsigned_char);
	return (UNITY_END());
}
