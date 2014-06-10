/*
 * CFE.h
 *
 *  Created on: Mar 20, 2014
 *      Author: Jason LaFrance
 */

#ifndef CFE_H_
#define CFE_H_

#include <vector>
#include <string>

class CFE {
private:
	unsigned long mNumber;
	std::vector<unsigned long> cfeList;
	void genCFE();

public:
	CFE(unsigned long);
	virtual ~CFE();

	std::vector<unsigned long> getCFE();
	std::string toString();
};

#endif /* CFE_H_ */
