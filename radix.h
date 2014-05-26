#ifndef RADIX_H
#define RADIX_H

#include <cmath>
#include <string>

/**
 * This header file contains algorithms for converting decimal numbers to (and from)
 * different radices ranging from 2 to 36. TODO: Extend capability to convert to
 * base-1 (though it can convert FROM base-1 just fine)
 * 
 * Copyright 2014 LastWhisper (https://github.com/LastWhisper) 
 */

std::string convert(int n, int radix) {
	if (n == 0)
		return "0"; // This is necessary since logf(0) creates a wormhole

	std::string number, digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	int j = n, k = n;
	for (int i = (int)(logf(n)/logf(radix)); i >= 0; i--) {
		j = k;
		k %= (int) pow(radix, i);
		number += digits[(j - k) / (int) pow(radix, i)];
	}
	
	return number;
}

int revert(std::string number, int radix) {
	int n = 0;
	std::string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	for (int i = 0; i < number.size(); i++)
		n += digits.find(number[i]) * (int) pow(radix, number.size()-1-i);
		
	return n;
}

#endif