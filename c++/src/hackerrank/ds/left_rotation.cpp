/**
 * https://www.hackerrank.com/challenges/array-left-rotation/problem
 * Pts: 20
 * 10/20/17
 */
#include <bits/stdc++.h>

using namespace std;

/**
 * @param {Number} n total number of elements
 * @param {Number} d number of shifts to left, pre-condition: d < n
 * @param {Number} i index to begin shifting from
 * @returns {Number} new index after shifting to left
 */
int shiftLeft(int n, int d, int i) {
	return (n - d + i) % n;
}

vector <int> leftRotation(vector <int> a, int d) {
    // Complete this function
	int noRotations = d;
	if (d > a.size()) {
		if (d % a.size() == 0) {
			return a;
		} else {
			noRotations = d % a.size(); 	
		}
	}
	if (noRotations < a.size() / 2) {
		for (int i = 0; i < noRotations; i++) {
			int a0 = a[0];
			for (int j = 0; j < a.size() -1; j++) {
				a[j] = a[j + 1];
			}
			a[a.size() -1] = a0;
		}
	} else { // right rotation
		for (int i = 0; i < a.size() - noRotations; i++) {
			int aLast = a[a.size() -1];
			for (int j = a.size() - 1; j >= 1; j--) {
				a[j] = a[j - 1];
			}
			a[0] = aLast;
		}
	}
	return a;
}

int main() {
    int n;
    int d;
    cin >> n >> d;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    vector <int> result = leftRotation(a, d);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? " " : "");
    }
    cout << endl;


    return 0;
}

