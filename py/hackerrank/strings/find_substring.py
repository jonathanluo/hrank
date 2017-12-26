# https://www.hackerrank.com/challenges/find-a-string/problem
def count_substring(str_in, sub_str):
    count = 0
    while True:
        idx = str_in.find(sub_str)
        if (idx is not -1):
            count += 1
        else:
            break
        len1 = len(str_in)
        str_in = str_in[idx+1:len1]
        #print str_in

    return count

if __name__ == '__main__':
    string = raw_input().strip()
    sub_string = raw_input().strip()

    count = count_substring(string, sub_string)
    print count

