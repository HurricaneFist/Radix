#include <cmath>
#include <iostream>
#include <string>
using namespace std;

string convert(int n, int radix) {
	if (n == 0)
		return "0"; // This is necessary since logf(0) creates a wormhole

	string number, digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	int j = n, k = n;
	for (int i = (int)(logf(n)/logf(radix)); i >= 0; i--) {
		j = k;
		k %= (int) pow(radix, i);
		number += digits[(j - k) / (int) pow(radix, i)];
	}
	
	return number;
}

int revert(string number, int radix) {
	int n = 0;
	string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	for (int i = 0; i < number.size(); i++)
		n += digits.find(number[i]) * (int) pow(radix, number.size()-1-i);
		
	return n;
}

int main() {
	cout << "1000 in hexadecimal: " << convert(1000, 16) << endl
	     << "3E8 in decimal: "      << revert("3E8", 16);
}