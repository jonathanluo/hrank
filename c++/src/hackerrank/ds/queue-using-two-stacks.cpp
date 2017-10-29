/**
 * https://www.hackerrank.com/challenges/queue-using-two-stacks/problem
 * 10/15/17 Pts: 45 R: 140244 
 */

#include <cmath>
#include <cstdio>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/**
 * Move elements from stack from to stack to 
 */
void moveElements(std::stack<int>& from, std::stack<int>& to) {
	while (!from.empty()) {
		to.push(from.top());
		from.pop();
	}
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    std::stack<int> s1;
    std::stack<int> s2;
    int n;
    cin >> n;
    while (n-- > 0) {
    	int type;
    	cin >> type;
    	if (type == 1) { // Enqueue element  into the end of the queue.
    		int data;
    		cin >> data;
    		if (!s2.empty()) {
    			moveElements(s2, s1);
    		}
    		s1.push(data);
    	} else if (type == 2) { //  Dequeue the element at the front of the queue.
    		if (s2.empty()) {
    			moveElements(s1, s2);
	    	}
    		s2.pop();
    	} else if (type == 3) { // Print the element at the front of the queue.
    		if (s2.empty()) {
    			moveElements(s1, s2);
	    	}
			cout << s2.top() << endl;
    	}
    }
    return 0;
}

/*
Sample Input
10
1 42
2
1 14
3
1 28
3
1 60
1 78
2
2

Sample Output
14
14
*/