/*
 * int_maths.cpp
 *
 *  Created on: Mar 20, 2014
 *      Author: Jason LaFrance
 */

#include "int_maths.h"

// deterministic, brute force primality test
// return: 	true if prime, false otherwise
bool isPrime(unsigned long n) {
	// is n in the primes set?
	if ((n & 1) == 0) {
		return (n == 2);
	}
	// filter out 0, 1, and all negative numbers
	if (n < 2) {
		return false;
	}
	// check 3 divisibility
	if (n == 3) {
		return true;
	}
	long rem = (n % 6);
	if (rem != 1 && rem != 5) {
		return false;
	}

	long max = iSqrt(n);
	// now only check 6k(+-)1 values
	for (long i = 5; i <= max; i += 6) {
		if ((n % i) == 0) {
			return false;
		}
		if ((n % (i + 2)) == 0) {
			return false;
		}
	}
	return true;
}

// standard implementation of a binary integer square root algorithm
// return:	 	 the integer portion of the square root of num
// precondition: a positive integer
unsigned long iSqrt(unsigned long num) {
	unsigned long res = 0;
	unsigned long bit = 1 << 30;

	while (bit > num)
		bit >>= 2;

	while (bit != 0) {
		if (num >= res + bit) {
			num -= res + bit;
			res = (res >> 1) + bit;
		} else
			res >>= 1;
		bit >>= 2;
	}
	return res;

}

// standard implementation of a binary greatest common denominator algorithm
// return: 	the greatest common denominator of u and v
unsigned long gcd(unsigned long u, unsigned long v) {
	long k = 0, t = 0, i;
	while (!(u & 1) && !(v & 1)) {
		k++;
		u >>= 1;
		v >>= 1;
	}
	if (u & 1)
		t = u;
	else
		t = -v;
	do {
		while (!(t & 1))
			t >>= 1;
		if (t > 0)
			u = t;
		else
			v = -t;
		t = u - v;
	} while (t > 0);
	for (i = 0; i < k; i++)
		u <<= 1;
	return u;
}


