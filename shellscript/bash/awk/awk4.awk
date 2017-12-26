awk '
# https://www.hackerrank.com/challenges/awk-4/problem
# BEGIN {
#  printf "---|Header|--\n"
# }

{
    ++cnt;
    if (cnt % 2 == 0) {
      print tt ";" $0;
    } else {
      tt=$0;
    }
}


END {
    if (cnt % 2 != 0) { # odd number of lines
      print $0 ";"
    }    
#  printf "---|Footer|---\n"
}

'
