/**
 * https://www.hackerrank.com/challenges/sparse-arrays/problem
 * 10/20/17 Pts: 163.52 R: 53054
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	unsigned int n;
	cin >> n;
	vector<string> v;
	while (n-- > 0) {
		string str;
		cin >> str;
		v.push_back(str);		
	}
	int q;
	cin >> q;
	while (q-- > 0) {
		string qstr;
		cin >> qstr;
		int count = 0;
		//for (auto it = v.begin(); it != v.end(); ++it) {
		for (auto it = begin (v); it != end (v); ++it) {
    		if (*it == qstr) count++;
		}
		cout << count << endl;
	}
    return 0;
}

/* 
#include <iostream>
#include <iterator>
#include <unordered_set>
using namespace std;

// from discussion - use unordered_multiset
int main() {
    int n, q, i;
    string str;
    unordered_multiset<string> s;
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> str;
        s.insert(str);
    }
    cin >> q;
    for (i = 0; i < q; ++i) {
        cin >> str;
        cout << s.count(str) << '\n';
    }
}
*/
/*
input:
4
aba
baba
aba
xzxb
3
aba
xzxb
ab

output:
2
1
0
*/

