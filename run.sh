#!/bin/bash

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run.sh                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/30 19:05:26 by vfurmane          #+#    #+#              #
#    Updated: 2020/12/30 19:05:28 by vfurmane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
# NC	\e[0m
# RED	\e[31m
# GREEN	\e[32m

source scripts/put.sh

# List of every function to test
funcs=("atoi")

# Create the directory for test scripts and logs
mkdir -p logs

# Compile all the tests
make all > /dev/null 2>&1 || error "Error when compiling the tests"

for func in $funcs
do
	./outs/ft_$func\_test.out > logs/$func.log
	if [ $? -eq 0 ]
	then
		ret_msg=$'\033[32mOK\033[0m'
	else
		ret_msg=$'\033[31mKO\033[0m'
	fi
	printf "%-20s [%s]\n" $func $ret_msg
done
