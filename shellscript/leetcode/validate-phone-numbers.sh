#!/bin/bash
#https://leetcode.com/problems/valid-phone-numbers/description/
#https://www.cyberciti.biz/faq/unix-howto-read-line-by-line-from-file/
#input="/path/to/txt/file"

pat1="^[0-9]{3}\-[0-9]{3}\-[0-9]{4}$"
pat2="^\([0-9]{3}\) [0-9]{3}\-[0-9]{4}$"

input=$1
#input="file.txt"    #leetcode
#IFS - Internal Field Separator
#while IFS= read -r var
while read -r var
do
    if [[ $var =~ $pat1 ]]; then
        echo "${var}"
        continue
    fi
    if [[ $var =~ $pat2 ]]; then
        echo "${var}"
    fi
done < "$input"

