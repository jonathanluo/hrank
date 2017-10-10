/*
 * https://www.hackerrank.com/challenges/cpp-lower-bound/problem
 * http://www.cplusplus.com/reference/algorithm/lower_bound/
 * 10/09/17 Pts: 379 R: 7674
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<int> v;
    while (n-- > 0) {
    	int data;
    	cin >> data;
    	v.push_back(data);
    }
    int q;
    cin >> q;
    while (q-- > 0) {
    	int query;
    	cin >> query;
    	// search against vector
		if (query < v[0]) {
			cout << "No 1" << endl;
		} else {
			std::vector<int>::iterator low,up;
			low=std::lower_bound (v.begin(), v.end(), query);
			if (std::binary_search(v.begin(), v.end(), query)) {
				cout << "Yes ";				
			} else {
				cout << "No ";
			}
			std::cout << (low- v.begin() + 1) << '\n'; 
    	}    	
    }
    return 0;
}


/*
Sample Input
8
1 1 2 2 6 9 9 15
4
1
4
9
15
 
Sample Output
Yes 1
No 5
Yes 6
Yes 8
 */