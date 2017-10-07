/*
    https://www.hackerrank.com/challenges/c-tutorial-basic-data-types/problem
    Points:   0 Rank: 230821 10/01/17
    Points:  15 Rank: 126507
    Points:  25 Rank: 107500
    Points:  35 Rank: 92368
    Points:  45 Rank: 82833
    Points:  55 Rank: 73629
    Points:  65 Rank: 65152
    Points:  70 Rank: 53767 10/01/17
    Points: 100 Rank: 38367 10/02/17
    Points: 140 Rank: 28127 10/03/17
    Points: 150 Rank: 25994 10/03/17
    Points: 160 Rank: 23744 10/04/17
    Points: 170 Rank: 22329 10/04/17
    Points: 180 Rank: 20843 10/04/17
    Points: 200 Rank: 18468 10/04/17
    Points: 224 Rank: 16301 10/06/17
    Points: 254 Rank: 13925 10/06/17

    Some C++ data types, their format specifiers, and their most common bit widths are as follows:

    Int ("%d"): 32 Bit integer
    Long ("%ld"): 64 bit integer
    Char ("%c"): Character type
    Float ("%f"): 32 bit real value
    Double ("%lf"): 64 bit real value

    10/01/17
*/

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int i;
    long l;
    char a;
    float f;
    double d;
    scanf("%d %ld %c %f %lf", &i, &l, &a, &f, &d);
    printf("%d\n%ld\n%c\n%.3f\n%.9lf", i, l, a, f, d);
    return 0;
}
