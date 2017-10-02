'''
https://www.hackerrank.com/challenges/python-lists/problem
https://www.hackerrank.com/domains/python/py-introduction
https://stackoverflow.com/questions/743806/how-to-split-a-string-into-a-list
09/19/17 hackos: 547
10/01/17
'''
if __name__ == '__main__':
    N = int(raw_input())
    mylist = []
    while (N > 0):
        action = raw_input()
        words = action.split()
        if (words[0] == "insert"):
            mylist.insert(int(words[1]), int(words[2]))
        elif (words[0] == "remove"):
            mylist.remove(int(words[1]))
        elif (words[0] == "append"):
            mylist.append(int(words[1]))
        elif (words[0] == "print"):
            print mylist
        elif (words[0] == "sort"):
            mylist.sort(cmp=None, key=None, reverse=False)
        elif (words[0] == "pop"):
            mylist.pop()
        elif (words[0] == "reverse"):
            mylist.reverse()
        N -= 1

'''
12
insert 0 5
insert 1 10
insert 0 6
print 
remove 6
append 9
append 1
sort 
print
pop
reverse
print
'''