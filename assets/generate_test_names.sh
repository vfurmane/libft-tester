#!/bin/bash

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    generate_test_names.sh                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/30 19:08:03 by vfurmane          #+#    #+#              #
#    Updated: 2020/12/30 19:08:03 by vfurmane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# cd to the script's directory
cd "$(dirname "$0")"

printf "===== Makefile =====\n\n"
for file in $(basename $(find ../test/tests -maxdepth 1 -name "ft_*_test.c"))
do
	printf "$file "
done
printf "\n\n"

printf "===== run.sh =====\n\n"
for file in $(basename $(find ../test/tests -maxdepth 1 -name "ft_*_test.c"))
do
	printf "\"$(basename $file | cut -d_ -f2)\" "
done
printf "\n\n"
