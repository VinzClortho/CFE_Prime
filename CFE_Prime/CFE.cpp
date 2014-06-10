/*
 * CFE.cpp
 *
 *  Created on: Mar 20, 2014
 *      Author: Jason LaFrance
 */

#include <iostream>
#include <string>
#include <sstream>

#include "CFE.h"
#include "int_maths.h"

// constructor and initialization
CFE::CFE(unsigned long n) {
	mNumber = n;
	cfeList.clear();
	genCFE();
}


CFE::~CFE() {
	cfeList.clear();
}

// generate the continued fraction expansion for the square root
// of mNumber.  This is done using purely algebraic methods to avoid
// having to deal with irrational numbers.  Also, since this is all
// done with binary and integer math, it's very fast.
//
// For a better idea of how this method works, here's the algebraic procedure that
// this was implemented from:
//
// http://www.maths.surrey.ac.uk/hosted-sites/R.Knott/Fibonacci/cfINTRO.html#sqrtalgsalg
void CFE::genCFE() {
	unsigned long e = iSqrt(mNumber);
	unsigned long a = e;
	unsigned long b = e;
	unsigned long c = 1;
	unsigned long n = mNumber;
	if (e * e == mNumber) {
		cfeList.push_back(e);
		return;
	}
	do {
		cfeList.push_back(a);
		unsigned long den = n - b * b;
		unsigned long an = ((e + b) * c) / den;
		unsigned long g = gcd(c, den);
		if (g > 1)
			c = den / g;
		else
			c = den;
		a = an;
		b = a * c - b;
	} while (c > 1);
	cfeList.push_back(2 * e);
}

// return the CFE list
std::vector<unsigned long> CFE::getCFE() {
	std::vector<unsigned long> ret = cfeList;
	return ret;
}

// Utility method!!
std::string CFE::toString() {
	std::ostringstream ret;
	ret << "[" << cfeList[0];

	if (cfeList.size() > 1) {
		ret << ": " << cfeList[1];
		for (unsigned int i = 2; i < cfeList.size(); i++) {
			ret << ", " << cfeList[i];
		}
	}

	ret << "]";
	return ret.str();
}

