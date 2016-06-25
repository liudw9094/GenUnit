/*
 * COrgGen.h
 *
 *  Created on: Dec 4, 2015
 *      Author: ldw
 */

#ifndef CORGGEN_H_
#define CORGGEN_H_

#include <string>
#include <vector>

class COrgGen
{
private:
	const std::vector<std::string>& m_args;
	std::string m_srcDir;
	std::string m_binDir;
	int m_numCases;
	int m_seed;
public:
	COrgGen(const std::vector<std::string>& args);
	~COrgGen();

	void enumCommands();
	bool parseCommands();
	void startTasks();
	void saveProfile();
	int run();

	inline std::string srcDir() const {return m_srcDir;}
	inline std::string binDir() const {return m_binDir;}
	inline int numCases() const {return m_numCases;}
	inline int seed() const {return m_seed;}
};

#endif /* CORGGEN_H_ */
