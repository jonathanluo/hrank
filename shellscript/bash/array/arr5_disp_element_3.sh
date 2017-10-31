# https://www.hackerrank.com/challenges/bash-tutorials-display-the-third-element-of-an-array/problem
# https://stackoverflow.com/questions/31143874/how-to-concatenate-arrays-in-bash
a=($(< /dev/stdin))
echo ${a[3]}
