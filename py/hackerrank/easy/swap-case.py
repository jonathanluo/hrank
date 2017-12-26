'''
https://www.hackerrank.com/challenges/swap-case/problem
'''
def swap_case(s):
    r=""
    for c in s:
        if c.islower():
            r += c.upper()
        else:
            r += c.lower()
    return r


if __name__ == '__main__':
    s = raw_input()
    result = swap_case(s)
    print result
