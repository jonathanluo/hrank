/*
 * https://www.hackerrank.com/challenges/cpp-maps/problem
 * 10/09/17 Pts: 409 R: 6807
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int n;
	cin >> n;
	std::map<string, int> m;
	while (n-- > 0) {
		int type;
		string name;
		cin >> type >> name;
		if (type == 1) {
			int mark;
			cin >> mark;
		    auto search = m.find(name);
		    if(search != m.end()) {
		        search->second += mark;
		    }
		    else {
				m.insert(make_pair(name, mark));
		    }			
		} else if (type == 2) {
			m.erase(name);
		} else if (type == 3) {
		    map<string, int>::iterator itr = m.find(name);
			if (itr != m.end()) {
				cout << itr->second << endl;
			} else {
				cout << "0" << endl;
			}
		}
	}
    return 0;
}

/*
7
1 Jesse 20
1 Jess 12
1 Jess 18
3 Jess
3 Jesse
2 Jess
3 Jess
*/