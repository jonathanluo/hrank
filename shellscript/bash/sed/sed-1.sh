# https://www.hackerrank.com/challenges/text-processing-in-linux-the-sed-command-1/problem
# https://stackoverflow.com/questions/1032023/sed-whole-word-search-and-replace
sed -e 's/\bthe\b/this/' < /dev/stdin
