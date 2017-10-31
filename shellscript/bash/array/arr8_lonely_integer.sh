# https://www.hackerrank.com/challenges/lonely-integer-2/problem
# https://stackoverflow.com/questions/2701400/remove-first-element-from-in-bash

read n
if [ "$n" -eq "1" ]; then
  read num
  echo $num
  exit 0;
fi

while ((n > 0))
do
	read num
    a=("${a[@]}" $num)
    n=$((n-1))
done

#echo ${a[@]}

x=${a[0]}
#echo $x
for i in "${a[*]:1}" # ${a[*]:1}
do
    #echo $i
    x=$(( x ^ i )) 
done
echo $x

#
#for i in ${arr[*]}
#do
#    ans=$(( $ans ^ $i ))
#done
#