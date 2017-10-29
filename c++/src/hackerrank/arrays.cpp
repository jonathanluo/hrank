/*
    https://www.hackerrank.com/challenges/arrays-introduction/problem
    10/01/17
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, array_size;
    cin >> array_size;
    n = array_size;
    int arr[n];
    int i = 0;
    while (n-- > 0) {
        cin >> arr[i];
        i++;
    }
    for (int i = array_size - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    return 0;
}
