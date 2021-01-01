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

# cd to the script's directory
cd "$(dirname "$0")"

# Do not display logs if KO
NOLOGS=0
# Check that all the files are present
CHECKFILES=0

# List of every function to test
funcs=()

# Parse arguments
source scripts/args.sh
# Message functions
source scripts/put.sh

if [ ${#funcs[@]} -eq 0 ]
then
	funcs=$(find test/tests -maxdepth 1 -name "ft_*_test.c" -exec sh -c "basename {} | cut -d_ -f2" \; | sort)
fi

# Create the directory for test scripts and logs
mkdir -p logs

# Compile all the tests
make all > /dev/null 2>&1 || error "Error when compiling the tests"

for func in ${funcs[@]}
do
	# Check that the script exists or not
	if ls outs/ft_$func\_test.out > /dev/null 2>&1
	then
		# Execute the test program and write the logs into a dedicated file
		./outs/ft_$func\_test.out > logs/$func.log
		# Display OK or KO according to the test's returned value
		if [ $? -eq 0 ]
		then
			ret_msg=$'\033[32mOK\033[0m'
			printf "%-20s [%s]\n" $func $ret_msg
		else
			ret_msg=$'\033[31mKO\033[0m'
			printf "%-20s [%s]\n" $func $ret_msg
			# Display logs if not disabled with --nologs
			if [ $NOLOGS -eq 0 ]
			then
				cat logs/$func.log
			fi
		fi
	else
		warn "Test file for $func doesn't exist"
	fi
	if [ $CHECKFILES -ne 0 ]
	then
		make checkfile FILE=ft_$func.c > /dev/null 2>&1 || warn "ft_$func.c file not found in the libft's directory"
	fi
done

make clean > /dev/null 2>&1
