/*
    https://www.hackerrank.com/challenges/c-tutorial-basic-data-types/problem
    Pts:   0 R: 230821 10/01/17
    Pts:  15 R: 126507
    Pts:  25 R: 107500
    Pts:  35 R: 92368
    Pts:  45 R: 82833
    Pts:  55 R: 73629
    Pts:  65 R: 65152
    Pts:  70 R: 53767 10/01/17
    Pts: 100 R: 38367 10/02/17
    Pts: 140 R: 28127 10/03/17
    Pts: 150 R: 25994 10/03/17
    Pts: 160 R: 23744 10/04/17
    Pts: 170 R: 22329 10/04/17
    Pts: 180 R: 20843 10/04/17
    Pts: 200 R: 18468 10/04/17
    Pts: 224 R: 16301 10/06/17
    Pts: 254 R: 13925 10/06/17
	Pts: 314 R: 10230 10/08/17
	Pts: 344 R:  8965 10/08/17
	Pts: 354 R:  8575 10/08/17

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
