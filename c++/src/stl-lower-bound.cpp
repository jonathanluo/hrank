/*
 * https://www.hackerrank.com/challenges/cpp-lower-bound/problem
 * 10/09/17
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
    	int i = 1;
    	bool found = false;
    	for(std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
    		if (*it == query) {
    			cout << "Yes " << i << endl;
    			found = true;
    			break;
    		} else if (*it < query) {
    			i++;
    			continue;
    		} else {
    			break;
    		}
		}
		if (!found) {
			cout << "No " << i << endl;
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