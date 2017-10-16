/**
 * https://www.hackerrank.com/challenges/queue-using-two-stacks/problem
 * 10/15/17 Pts: 45 R: 140244
 *          Pts: 75 R: 102641
 */

#include <cmath>
#include <cstdio>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    std::vector<int> v;
    int n;
    cin >> n;
    while (n-- > 0) {
    	int type;
    	cin >> type;
    	if (type == 1) { // Enqueue element  into the end of the queue.
    		int data;
    		cin >> data;
    		v.push_back(data);
    	} else if (type == 2) { // Dequeue the element at the front of the queue.
    		if (!v.empty())
    			v.erase(v.begin());
    	} else if (type == 3) { // Print the element at the front of the queue.
    		if (!v.empty())
				cout << v.front() << endl;
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