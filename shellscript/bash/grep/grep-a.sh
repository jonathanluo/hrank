# https://www.hackerrank.com/challenges/text-processing-in-linux-the-grep-command-4/problem
# grep multiple words at the same time

grep -iw 'the\|that\|then\|those' < /dev/stdin
# grep -iw -e "the" -e "that" -e "then" -e "those" < /dev/stdin


