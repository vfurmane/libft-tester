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

printf "===== Makefile =====\n\n"
for file in $(ls test/tests)
do
	printf "$file "
done
printf "\n\n"

printf "===== run.sh =====\n\n"
for file in $(ls test/tests)
do
	printf "\"$(basename $file | cut -d_ -f2)\" "
done
printf "\n\n"
