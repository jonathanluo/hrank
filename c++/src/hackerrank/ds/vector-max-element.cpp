/**
 * https://www.hackerrank.com/challenges/maximum-element/problem
 * 10/15/17 Pts: 45 R: 140244
 *
 * Cloned from stack-max-element.cpp, re-implement using vector  
 */

#include <cmath>
#include <cstdio>
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
    std::vector<itemWithMaxValue> v;
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
    		if (!v.empty()) {
	    		itemWithMaxValue itemTop = v.back();
    			item.maxValue = (itemTop.maxValue > data) ? itemTop.maxValue : data;
    		} else {
    			item.maxValue = data;
    		}
    		v.push_back(item);
    	} else if (type == 2) {
    		if (v.size() > 0) {
	    		v.pop_back();
	    	}
    	} else if (type == 3) {
    		if (!v.empty()) {
	    		itemWithMaxValue itemTop = v.back();
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