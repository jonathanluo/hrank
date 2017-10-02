'''
https://www.hackerrank.com/challenges/list-comprehensions/problem

http://www.secnetix.de/olli/Python/list_comprehensions.hawk
    The above example also demonstrates that you can do exactly the same thing with map() and a lambda function. 
    However, there are cases when you cannot use map() and have to use a list comprehension instead, or vice 
    versa. When you can use both, then it is often preferable to use a list comprehension, because this is more
    efficient and easier to read, most of the time.

Discussions:
    x, y, z, n = int(input()), int(input()), int(input()), int(input())
    print ([[a,b,c] for a in range(0,x+1) for b in range(0,y+1) for c in range(0,z+1) if a + b + c != n ])

        Looks good, but to avoid those repetitive input calls you could do something like:
        x, y, z, n = (int(input()) for _ in range(4))
        
        _ : https://stackoverflow.com/questions/5893163/what-is-the-purpose-of-the-single-underscore-variable-in-python

    x,y,z,n = [input() for i in range(4)]
    print [[a,b,c] for a in range(x+1) for b in range(y+1) for c in range(z+1) if a+b+c != n]

    nice solution. But instead of range[0,x] you could do
    print ([[a,b,c] for a in range(x+1) for b in range(y+1) for c in range(z+1) if a + b + c != n ])

10/01/17
'''
if __name__ == '__main__':
    x = int(raw_input())
    y = int(raw_input())
    z = int(raw_input())
    n = int(raw_input())
    i = 0; j = 0; k = 0;
    list1 = [[a,b,c] for a in range(0,x+1) for b in range(0,y+1) for c in range(0,z+1) if a + b + c != n ]
    print list1
