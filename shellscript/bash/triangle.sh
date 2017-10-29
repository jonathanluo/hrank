# http://www.tldp.org/LDP/abs/html/arithexp.html
# https://bash.cyberciti.biz/guide/Perform_arithmetic_operations
read x
read y
read z

: $[  xz=x+z ]
: $(( xy=x+y ))
yz=$(( y+z ))

if [[ "$x" -lt "1" || "$x" -gt "1000" ]]; then
   exit;
fi
if [[ "$y" -lt "1" || "$y" -gt "1000" ]]; then
   exit;
fi
if [[ "$z" -lt "1" || "$z" -gt "1000" ]]; then
   exit;
fi

if [[ "$xy" -gt "$z" && "$xz" -gt "$y" && "$yz" -gt "$x" ]]; then
    if [[ "$x" -eq "$y" && "$y" -eq "$z" ]]; then
        echo "EQUILATERAL"
    elif [[ "$x" -eq "$y" || "$y" -eq "$z" || "$x" -eq "$z" ]]; then
        echo "ISOSCELES"
    else
        echo "SCALENE"
    fi
fi
