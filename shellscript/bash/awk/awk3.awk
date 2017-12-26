awk '{
# https://www.hackerrank.com/challenges/awk-3/problem
avg = $2 + $3 + $4; 
avg /= 3; 

if (avg < 50)
    print $0 " : FAIL"
else if (avg > 50 && avg < 60)
    print $0 " : C"
else if (avg > 60 && avg < 80)
    print $0 " : B"
else if (avg > 80)
    print $0 " : A"
}'
