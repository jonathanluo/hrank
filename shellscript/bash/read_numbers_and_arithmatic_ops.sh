#!/bin/bash

# http://tldp.org/LDP/abs/html/ops.html
# https://www.hackerrank.com/challenges/bash-tutorials---the-world-of-numbers/problem
read n1
read n2


let "sum = $n1 + $n2"
echo $sum

: $((n = $n1 -$n2 ))
echo $n

n=$[ $n1 * $n2 ]
echo $n

: $((n = $n1 / $n2 ))
echo $n


