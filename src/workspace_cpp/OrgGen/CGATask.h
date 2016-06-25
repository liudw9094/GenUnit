/*
 * CGATask.h
 *
 *  Created on: Dec 4, 2015
 *      Author: ldw
 */

#ifndef CGATASK_H_
#define CGATASK_H_

#include <string>

class COrgGen;

class CGATask {
private:
	std::string m_srcDir;
	std::string m_binDir;
	int m_seedOrin;
	int m_nIndex;
	int m_seed;
public:
	CGATask(const COrgGen& gen, int nIndex);
	~CGATask();

	int run();
private:
	void safeinfo();
};

#endif /* CGATASK_H_ */
