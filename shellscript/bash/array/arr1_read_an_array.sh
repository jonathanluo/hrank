# https://www.hackerrank.com/challenges/bash-tutorials-read-in-an-array/problem

# Input Format
#   A list of country names. The only characters present in the country names will be upper or lower case characters and hyphens.
# Output Format
#   Display the entire array of country names, with a space between each of them.

# arr=($(cat))  
# echo ${arr[*]}

# a=($(cat))
# echo ${a[@]}
# echo ${a[0]}
# echo ${a[1]}

# echo $(< /dev/stdin)

a=($(cat))
echo $a
