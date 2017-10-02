'''
https://www.hackerrank.com/challenges/find-second-maximum-number-in-a-list/problem
10/01/17 Points: 105 Rank: 55062
'''

if __name__ == "__main__":
    n = int(raw_input())
    arr = map(int, raw_input().split())
    arr.sort(cmp=None, key=None, reverse=True)
    #print(arr)
    max1 = arr[0]
    max2 = 0
    i = 1
    while i < arr.__len__():
        if arr[i] < max1:
            max2 = arr[i]
            break;
        i += 1
    print max2
