/**
 * https://www.hackerrank.com/challenges/maximum-element/problem
 * 10/15/17 Pts: 45 R: 140244 
 */

#include <cmath>
#include <cstdio>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct itemWithMaxValue {
	int data;
	int maxValue;
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    std::stack<itemWithMaxValue> s;
    int n;
    cin >> n;
    while (n-- > 0) {
    	int type;
    	cin >> type;
    	if (type == 1) {
    		int data;
    		cin >> data;
    		itemWithMaxValue item;
    		item.data = data;
    		if (s.size() > 0) {
	    		itemWithMaxValue itemTop = s.top();
    			item.maxValue = (itemTop.maxValue > data) ? itemTop.maxValue : data;
    		} else {
    			item.maxValue = data;
    		}
    		s.push(item);
    	} else if (type == 2) {
    		if (s.size() > 0) {
	    		s.pop();
	    	}
    	} else if (type == 3) {
    		if (!s.empty()) {
	    		itemWithMaxValue itemTop = s.top();
				cout << itemTop.maxValue << endl;
			}    		
    	}
    }
    return 0;
}

/*
Sample Input
10
1 97
2
1 20
2
1 26
1 20
2
3
1 91
3

Sample Output
26
91
*/