/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:14:46 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/06 15:42:41 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	ft_putchar_fd_basic(void)
{
	char	chr = 'W';
	/* -------------------------------- */
	char	buffer[2];
	int		out_pipe[2];
	int		saved_stdout;

	saved_stdout = dup(STDOUT_FILENO);
	if (pipe(out_pipe) != 0)
		exit(1);
	dup2(out_pipe[1], STDOUT_FILENO);
	close(out_pipe[1]);
	/* -------------------------------- */
	ft_putchar_fd(chr, 1);
	/* -------------------------------- */
	fflush(stdout);
	read(out_pipe[0], buffer, 1);
	buffer[1] = '\0';
	dup2(saved_stdout, STDOUT_FILENO);
	TEST_ASSERT_EQUAL_STRING("W", buffer);
}

void	ft_putchar_fd_unsigned_char(void)
{
	int		chr = 343;
	/* -------------------------------- */
	char	buffer[2];
	int		out_pipe[2];
	int		saved_stdout;

	saved_stdout = dup(STDOUT_FILENO);
	if (pipe(out_pipe) != 0)
		exit(1);
	dup2(out_pipe[1], STDOUT_FILENO);
	close(out_pipe[1]);
	/* -------------------------------- */
	ft_putchar_fd(chr, 1);
	/* -------------------------------- */
	fflush(stdout);
	read(out_pipe[0], buffer, 1);
	buffer[1] = '\0';
	dup2(saved_stdout, STDOUT_FILENO);
	printf("Hello World\n");
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
