/*
    https://www.hackerrank.com/challenges/c-tutorial-basic-data-types/problem
    Points:   0 Rank: 230821
    Points:  15 Rank: 126507
    Points:  25 Rank: 107500
    Points:  35 Rank: 92368
    Points:  45 Rank: 82833
    Points:  55 Rank: 73629
    Points:  65 Rank: 65152
    Points:  70 Rank: 53767
    Points: 100 Rank: 38367

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
