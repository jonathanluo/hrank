'''
https://www.hackerrank.com/challenges/nested-list/problem
https://docs.python.org/2/tutorial/datastructures.html#list-comprehensions
https://stackoverflow.com/questions/6666748/python-sort-list-of-lists-ascending-and-then-decending
10/06/17
'''
if __name__ == '__main__':
    n = int(raw_input())
    lst = [[] for _ in range(n)]
    for i in range(n):
        name = raw_input()
        score = float(raw_input())
        lst[i].append(name)
        lst[i].append(score)
    

    print lst
    lst.sort(key=lambda k: (-k[1], -k[0]), reverse=True)
    print lst

'''
5
Harry
37.21
Berry
37.21
Tina
37.2
Akriti
41
Harsh
39

lst.sort(key=lambda k: (-k[1]), reverse=True)
[['Harry', 37.21], ['Berry', 37.21], ['Tina', 37.2], ['Akriti', 41.0], ['Harsh', 39.0]]
[['Tina', 37.2], ['Harry', 37.21], ['Berry', 37.21], ['Harsh', 39.0], ['Akriti', 41.0]]
'''