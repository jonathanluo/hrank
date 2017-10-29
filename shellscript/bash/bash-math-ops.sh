let "n++"          # let "++n"  also works.
echo -n "$n "

(( n++ ))          # (( ++n ))  also works.
echo -n "$n "

: $(( n++ ))       # : $(( ++n )) also works.
echo -n "$n "

: $[ n++ ]         # : $[ ++n ] also works
