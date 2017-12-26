awk '
# https://www.hackerrank.com/challenges/awk-1/problem
# BEGIN {
#  printf "---|Header|--\n"
# }

{
  if (NF < 4) {
      print "Not all scores are available for " $1
  }
}

END {
#  printf "---|Footer|---\n"
}

'
