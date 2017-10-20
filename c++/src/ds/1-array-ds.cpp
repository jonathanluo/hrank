/*
 * https://www.hackerrank.com/challenges/arrays-ds/problem
 * 10/14/17 Pts  0   	R: > 300000
 *          Pts  10  	R: 238647
 * 10/15/17 Pts: 25  	R: 175751
 *          Pts: 45  	R: 140244
 *          Pts: 75  	R: 102641
 * 10/18/17	Pts: 100 	R:  82944
 * 10/19/17 Pts: 118.52 R: 	73507
 */
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
    }
    for(int arr_i = n-1;arr_i >=0;arr_i--){
       cout << arr[arr_i] << " ";
    }
    
    return 0;
}
