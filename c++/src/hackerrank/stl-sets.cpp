/*
 * https://www.hackerrank.com/challenges/cpp-sets/problem
 * 10/09/17 Pts: 394 R: 7207
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int n;
	cin >> n;
	std::set<int> s;
	while (n-- > 0) {
		int type, data;
		cin >> type >> data;
		if (type == 1) {
			s.insert(data);
		} else if (type == 2) {
			s.erase(data);
		} else if (type == 3) {
			set<int>::iterator itr = s.find(data);
			if (itr != s.end()) {
				cout << "Yes" << endl;
			} else {
				cout << "No" << endl;
			}
		}
	}
    return 0;
}

 
 
/*
Sample Input
8
1 9
1 6
1 10
1 4
3 6
3 14
2 6
3 6

Sample Output
Yes
No
No
*/