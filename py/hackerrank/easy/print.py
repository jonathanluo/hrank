'''
https://www.hackerrank.com/challenges/python-print/problem
10/01/17 hackos 615

if __name__ == '__main__':
    n = int(raw_input())
    i = 0
    while n > 0:
        print str(i),
        i += 1
        n -= 1
'''

from __future__ import print_function

if __name__ == '__main__':
    n = int(raw_input())
    i = 1
    while n > 0:
        print(str(i), end='')
        i += 1
        n -= 1