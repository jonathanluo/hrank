# https://www.hackerrank.com/challenges/bash-tutorials-concatenate-an-array-with-itself/problem
# https://stackoverflow.com/questions/31143874/how-to-concatenate-arrays-in-bash
a=($(< /dev/stdin))
a=( "${a[@]}" "${a[@]}" "${a[@]}")
echo ${a[@]}
