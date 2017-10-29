sum=0
read N
for ((n=0;n<N;n++))
do
    read d
    sum=$(( sum + d ))    
done
printf "%.3f" $(echo "$sum/$N" | bc -l)
