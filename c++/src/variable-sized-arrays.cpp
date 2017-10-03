/*
    https://www.hackerrank.com/challenges/variable-sized-arrays/problem
    10/02/17
    Points: 100 Rank: 38367
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
2 2
3 1 5 4
5 1 2 8 9 3
0 1
1 3
*/
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, q;
    cin >> n; // number of arraries
    cin >> q; // number of queries
    int** data = new int*[n];
    int i = 0;
    while (i < n) {
        int arrsize;
        cin >> arrsize;
        data[i] = new int[arrsize];
        int j = 0;
        while (j < arrsize) {
            cin >> data[i][j];
            j++;
        }
        for (int j = 0; j < arrsize; j++) {
            //cout << data[i][j] << " ";
        }
        i++;
    }
    while (q-- > 0) {
        int i, j;
        scanf("%d %d", &i, &j);
        cout << data[i][j] << endl;
    }
    i = 0;
    while (i < n) {
        delete[] data[i];
        i++;
    }
    delete[] data;
    return 0;
}

