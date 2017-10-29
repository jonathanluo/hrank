#!/bin/bash
#
# https://www.hackerrank.com/challenges/bash-tutorials---comparing-numbers/problem 
# http://tldp.org/LDP/abs/html/comparison-ops.html
# https://stackoverflow.com/questions/18668556/comparing-numbers-in-bash

read n1
read n2

if (( $n1 > $n2 )); then
    echo "X is greater than Y"
fi

if (( $n1 == $n2 )); then
    echo "X is equal to Y"
fi

if [  "$n1" -lt "$n2" ]; then
    echo "X is less than Y"
fi

