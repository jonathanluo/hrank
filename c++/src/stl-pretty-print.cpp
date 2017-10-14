/*
 * https://www.hackerrank.com/challenges/prettyprint/problem
 * http://www.dreamincode.net/forums/topic/301700-setw-and-align-right-and-left-question/
 * https://www.tutorialspoint.com/cpp_standard_library/cpp_setfill.htm
 * http://www.cplusplus.com/reference/ios/showpos/
 *
 * 10/13/17 Pts: 429 R: 6048 
 */ 

#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	//cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;
		//int n = static_cast<int>(A);

		ios_base::fmtflags flags = cout.flags();
		cout << setw(0) << "0x" << hex << nouppercase << left << (long long)A << endl;
		
		cout.flags(flags);  //reset flags
		//cout << fixed << setw(15) << setprecision(2) << setfill('_') << right << showpos << B << endl; // std::showpos <=> std::noshowpos
        
        cout << dec << right << setw(15) << setfill('_') << showpos << fixed << setprecision(2); // formatting
        cout << B << endl; // actual printed part
        
		std::cout.copyfmt(std::ios(NULL)); // cout.flags(flags);
		cout << scientific << setw(15) << setprecision(9) << noshowbase << right << uppercase << C << endl;
		cout.flags(flags);

	}
	return 0;

}

/*
Sample Input
1  
100.345 2006.008 2331.41592653498

Sample Output
0x64             
_______+2006.01  
2.331415927E+03
*/
