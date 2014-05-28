#ifndef RADIX_H
#define RADIX_H

#include <cmath>
#include <string>

/**
 * This header file contains algorithms for converting decimal numbers to (and from)
 * different radices ranging from 2 to 36. TODO: Extend capability to convert to
 * base-1 (though it can convert FROM base-1 just fine)
 * 
 * https://github.com/LastWhisper
 */

std::string convert(unsigned long long n, int radix) {
	if (n == 0)
		return "0"; // This is necessary since logf(0) creates a wormhole

	std::string number, digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	unsigned long long j = n, k = n;
	for (int i = (int)(logf(n)/logf(radix)); i >= 0; i--) {
		j = k;
		k %= (int) pow(radix, i);
		number += digits[(j - k) / (int) pow(radix, i)];
	}
	
	return number;
}

unsigned long long revert(std::string number, int radix) {
	unsigned long long n = 0;
	std::string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	for (int i = 0; i < number.size(); i++)
		n += digits.find(number[i]) * (unsigned long long) pow(radix, number.size()-1-i);
		
	return n;
}

std::string transvert(std::string number, int original_radix, int new_radix) {
	return convert(revert(number, original_radix), new_radix);
}

#endif
