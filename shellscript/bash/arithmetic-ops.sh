read expression;
#echo "scale=3; $expression" | bc
printf "%.3f" $(echo $expression | bc -l)
