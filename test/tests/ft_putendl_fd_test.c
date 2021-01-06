/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:14:46 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/06 17:54:06 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	ft_putendl_fd_basic(void)
{
	char	*str = "Hello World";
	/* -------------------------------- */
	char	buffer[13];
	int		out_pipe[2];
	int		saved_stdout;

	saved_stdout = dup(STDOUT_FILENO);
	if (pipe(out_pipe) != 0)
		exit(1);
	dup2(out_pipe[1], STDOUT_FILENO);
	close(out_pipe[1]);
	/* -------------------------------- */
	ft_putendl_fd(str, 1);
	/* -------------------------------- */
	fflush(stdout);
	read(out_pipe[0], buffer, 12);
	buffer[12] = '\0';
	dup2(saved_stdout, STDOUT_FILENO);
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
