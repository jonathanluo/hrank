'''
Created on Sep 19, 2017
https://www.hackerrank.com/challenges/py-if-else/problem
https://www.hackerrank.com/domains/python/py-introduction
hackos: 537
'''

if __name__ == '__main__':
    n = int(input())
    if (n % 2 != 0):
        print "Weird"
    else:
        if (2 <= n and n <= 5):
            print "Not Weird"
        elif (6 <= n and n <= 20):
            print "Weird"
        elif n > 20:
            print "Not Weird"

