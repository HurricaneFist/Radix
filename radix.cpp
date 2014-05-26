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

int revert(string number, int radix); // TODO

int main() {
	for (int i = 1; i <= 65536; i *= 16)
		cout << convert(i, 16) << endl; // hexadecimal numbers
}