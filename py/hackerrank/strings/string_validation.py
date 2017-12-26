'''
https://www.hackerrank.com/challenges/string-validators/problem
input - Test case #3:

#$%@^&*kjnk svskjnbui h 4oi3hheuh /dfh uidshvhdsuihv suihc 0hrem89m4c02mw4xo;,wh fwhncoishmxlxfkjsahnxu83v 08 n8OHOIHIOMOICWHOFCMHEOFMCOEJMC0J09C 03J J3L;JMFC3JM3JC3'JIOO9MMJ099U N090N9 OOHOLNHNLLKNLKNKNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK3333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333000000000000000000000000000000000000000000000000000000000000000000000000000

expected output:
True
True
True
True
True
'''
if __name__ == '__main__':
    s = raw_input()

    ret = False
    for c in s:
        if c.isalnum():
            ret = True
            break
    print ret

    ret = False
    for c in s:
        if c.isalpha():
            ret = True
            break
    print ret

    ret = False
    for c in s:
        if c.isdigit():
            ret = True
            break
    print ret

    ret = False
    for c in s:
        if c.islower():
            ret = True
            break
    print ret

    ret = False
    for c in s:
        if c.isupper():
            ret = True
            break
    print ret

