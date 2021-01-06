/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:14:46 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/06 19:11:10 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	ft_putnbr_fd_basic(void)
{
	int	nbr = 42;
	/* -------------------------------- */
	char	buffer[3];
	int		out_pipe[2];
	int		saved_stdout;

	saved_stdout = dup(STDOUT_FILENO);
	if (pipe(out_pipe) != 0)
		exit(1);
	dup2(out_pipe[1], STDOUT_FILENO);
	close(out_pipe[1]);
	/* -------------------------------- */
	ft_putnbr_fd(nbr, 1);
	/* -------------------------------- */
	fflush(stdout);
	read(out_pipe[0], buffer, 2);
	buffer[2] = '\0';
	dup2(saved_stdout, STDOUT_FILENO);
	TEST_ASSERT_EQUAL_STRING("42", buffer);
}

void	ft_putnbr_fd_negative(void)
{
	int	nbr = -42;
	/* -------------------------------- */
	char	buffer[3];
	int		out_pipe[2];
	int		saved_stdout;

	saved_stdout = dup(STDOUT_FILENO);
	if (pipe(out_pipe) != 0)
		exit(1);
	dup2(out_pipe[1], STDOUT_FILENO);
	close(out_pipe[1]);
	/* -------------------------------- */
	ft_putnbr_fd(nbr, 1);
	/* -------------------------------- */
	fflush(stdout);
	read(out_pipe[0], buffer, 2);
	buffer[2] = '\0';
	dup2(saved_stdout, STDOUT_FILENO);
	TEST_ASSERT_EQUAL_STRING("-42", buffer);
}

void	ft_putnbr_fd_big_number(void)
{
	int	nbr = 2147483647;
	/* -------------------------------- */
	char	buffer[11];
	int		out_pipe[2];
	int		saved_stdout;

	saved_stdout = dup(STDOUT_FILENO);
	if (pipe(out_pipe) != 0)
		exit(1);
	dup2(out_pipe[1], STDOUT_FILENO);
	close(out_pipe[1]);
	/* -------------------------------- */
	ft_putnbr_fd(nbr, 1);
	/* -------------------------------- */
	fflush(stdout);
	read(out_pipe[0], buffer, 10);
	buffer[10] = '\0';
	dup2(saved_stdout, STDOUT_FILENO);
	TEST_ASSERT_EQUAL_STRING("2147483647", buffer);
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
	RUN_TEST(ft_putnbr_fd_basic);
	RUN_TEST(ft_putnbr_fd_negative);
	//RUN_TEST(ft_putnbr_fd_big_number);
	return (UNITY_END());
}
