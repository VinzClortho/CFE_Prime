/*
 * Code to test my conjecture that if a number n is prime, and the continued
 * fraction expansion of the square root of n has an odd number of terms
 * up to and including the end of the first period, then the middle term must
 * be the closest odd number not exceeding the value of the integer portion of
 * the square root of n.
 *
 * main.cpp
 *
 *  Created on: Mar 20, 2014
 *      Author: Jason LaFrance
 */

#include <iostream>
#include <climits>
#include <vector>

#include "CFE.h"
#include "int_maths.h"

bool isPrime(unsigned long);

#define COUNTER_INTERVAL 10000

int main(int argc, const char* argv[]) {
	unsigned int counter = 0;
	unsigned long checkPoint = COUNTER_INTERVAL;
	// run forever, or until the conjecture fails
	for (unsigned long i = 1;; i++) {
		if (counter == COUNTER_INTERVAL) {
			checkPoint += COUNTER_INTERVAL;
			std::cout << "checking to " << checkPoint << std::endl;
			counter = 0;
		} else {
			counter++;
		}

		if (!isPrime(i))
			continue;

		CFE cfe(i);
		std::vector<unsigned long> cf = cfe.getCFE();

		long t = cf[0];
		if ((t & 1) == 0)
			t--;

		if ((cf.size() & 1) == 1) {
			int index = cf.size() / 2;
			if (cf[index] != t && isPrime(i)) {
				std::cout << "Found an even mediant!  Conjecture false!\t" << i
						<< " " << cfe.toString() << std::endl;
				return 0;
			}
		}
	}
}

