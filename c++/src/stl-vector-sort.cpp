/*
 * https://www.hackerrank.com/challenges/vector-sort/problem
 * Points: 354 R: 8575 10/08/17
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
    vector<int>v;
    while (n-- > 0) {
        int data;
        cin >> data;
        v.push_back(data);
    }
    std::sort(v.begin(),v.end());
    for (std::vector<int>::const_iterator i = v.begin(); i != v.end(); ++i)
    	std::cout << *i << ' ';
    return 0;
}

/*
5
1 6 10 8 4
*/
