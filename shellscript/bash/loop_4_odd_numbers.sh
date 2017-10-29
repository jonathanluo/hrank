#!/bin/bash

# https://www.hackerrank.com/challenges/bash-tutorials---looping-and-skipping/problem
# http://go2linux.garron.me/bash-for-loop/

for i in {1..99} 
do
    if [ $((i % 2)) -eq 0 ];
    then
        #echo "even";
        :
    else
        echo $i;
    fi
done
