/*
 * https://www.hackerrank.com/challenges/vector-erase/problem
 * Pts: 364 R: 8174 10/08/17
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
    int toErase;
    int toEraseBegin, toEraseEnd;
    cin >> toErase >> toEraseBegin >> toEraseEnd;
    v.erase(v.begin() + toErase - 1);
//    for (std::vector<int>::const_iterator i = v.begin(); i != v.end(); ++i)
//    	std::cout << *i << ' ';
//	std::cout << endl;

    v.erase(v.begin() + toEraseBegin - 1, v.begin() + toEraseEnd - 1);
    std::cout << v.size() << endl;
    for (std::vector<int>::const_iterator i = v.begin(); i != v.end(); ++i)
    	std::cout << *i << ' ';
	std::cout << endl;
    return 0;
}

/*
6
1 4 6 2 8 9
2
2 4

3
1 8 9
*/
