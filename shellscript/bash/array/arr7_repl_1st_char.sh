# https://www.hackerrank.com/challenges/bash-tutorials-remove-the-first-capital-letter-from-each-array-element/problem
# 
a=($(< /dev/stdin))
b=(${a[@]/^[A-Z]/./})
echo ${b[@]}

#echo ${a[@]/[A-Z]/.}

#readarray ary
#echo ${ary[@]//[[:upper:]]/.}

#arr=($(cat))
#echo ${arr[@]/#[A-Z]/.}
