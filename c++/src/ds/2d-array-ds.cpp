/*
 * https://www.hackerrank.com/challenges/2d-array/problem
 */
 #include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int maxVal(vector< vector<int> >& arr, int startRow, int startCol) {
	int sum = 0;
    for(int row = startRow; row < startRow + 3; row++){
       	for(int col = startCol; col < startCol + 3; col++) {
       		if (row == startRow || row == startRow + 2) {
       			sum += arr[row][col];
       		} else if (row == startRow +1 && col == startCol + 1) {
       			sum += arr[row][col];
       		}
       	}
    }
    return sum;
}

int main() {
    vector< vector<int> > arr(6, vector<int>(6));
    for (int row = 0;row < 6;row++){
       for (int col = 0;col < 6;col++){
          cin >> arr[row][col];
       }
    }
    int max = INT32_MIN;
    // 3 x 3 hourglasses
    for (int row = 0; row < 4; row++) {
       	for (int col = 0; col < 4; col++) {
			int maxValue = maxVal(arr, row, col);
			if (maxValue > max) {
			max = maxValue;
			}
       	}
    }
    cout << max << endl;
    return 0;
}

/*
Sample Input
1 1 1 0 0 0
0 1 0 0 0 0
1 1 1 0 0 0
0 0 2 4 4 0
0 0 0 2 0 0
0 0 1 2 4 0

Sample Output
19
*/