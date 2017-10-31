/*
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
