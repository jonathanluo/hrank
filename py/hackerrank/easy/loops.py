'''
https://www.hackerrank.com/challenges/python-loops/problem
10/01/17
'''
if __name__ == '__main__':
    n = int(raw_input())
    i = 0
    while (n > 0):
        print i*i
        i += 1
        n -= 1;
