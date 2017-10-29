# https://www.hackerrank.com/challenges/bash-tutorials-slice-an-array/problem
# https://gist.github.com/steakknife/8294792
#   ${X[@]}                                        the usual whole array
#   ${X[@]:index:length}                           slice from index to index+length-1 inclusive
#   ${X[@]::length}                                slice from 0 to length-1 inclusive
#   ${X[@]:index}                                  slice from index to end of array inclusive
#   X=( "${X[@]}" )                                compact X
#   X=( "${X[@]::$INDEX}" "${X[@]:$((INDEX+1))}" ) remove element at INDEX and compact array

#a=($(cat))
a=($(< /dev/stdin))
echo ${a[@]:3:5}

