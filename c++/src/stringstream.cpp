/**
 * https://www.hackerrank.com/challenges/c-tutorial-stringstream/problem 
 * http://www.dreamincode.net/forums/topic/95826-stringstream-tutorial/
 * https://stackoverflow.com/questions/20572203/detect-when-at-the-end-of-a-stringstream
 * https://stackoverflow.com/questions/11719538/how-to-use-stringstream-to-separate-comma-separated-strings
 *
 * 10/04/17
 */
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
    // Complete this function
    stringstream ss(str);
    vector<int> vi;
    int number;
    char ch;
    while (ss >> number) {
        vi.push_back(number);
        ss >> ch;
    }
    return vi;
}

/*
23,4,56
*/
int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for (unsigned int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }

    return 0;
}
