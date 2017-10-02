'''
https://www.hackerrank.com/challenges/python-tuples/problem
https://stackoverflow.com/questions/10973766/understanding-the-map-function
    map(f, iterable)
    is basically equivalent to:
    [f(x) for x in iterable]

tuple is immutable
10/01/17
'''
if __name__ == '__main__':
    n = int(raw_input())
    integer_list = map(int, raw_input().split()) # apply int function to a list of iterable and return an integer list 
    t = tuple(integer_list)
    print hash(t) # list cannot be hashed, but a tuple is okay
