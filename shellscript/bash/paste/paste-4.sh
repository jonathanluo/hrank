# https://www.hackerrank.com/challenges/paste-4/problem
# Restructure the file in such a way, that every group of three consecutive 
# rows are folded into one, and separated by tab.
paste -sd $'\t\t\n' < /dev/stdin

