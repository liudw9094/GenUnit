/*
 * CDataTest.h
 *
 *  Created on: Dec 5, 2015
 *      Author: ldw
 */

#ifndef CDATATEST_H_
#define CDATATEST_H_

#include <string>
#include <vector>

class CDataTest {
private:
	const std::vector<std::string>& m_args;
	std::string m_binDir;
	std::string m_txDir;
	std::string m_groupDir;
	enum _MODE
	{
		MODE_ONE, MODE_GROUP
	} m_mode;

	std::string m_curDir;
	std::string m_evoRuntimePath;
	std::string m_emmaPath;
	std::string m_junitPath;
	std::string m_hamcrestPath;
	std::string m_runtestPath;
	std::string m_outputBinDir;
	std::string m_outputReportDir;

	std::vector<std::string> m_testFiles;
	std::vector<std::string> m_testFileDependency;

	std::vector<std::string> m_classNames;
public:
	CDataTest(const std::vector<std::string>& args);
	~CDataTest();

	int run();
private:
	int runModeOne();
	int runModeGroup();
	bool parseCommands();
	void showCommands();
	bool findTestFiles();
	int compileTests();
	int compileTestFile(const std::string& filepath);
	int runTests();
	int executeATest(const std::string& className);
};

#endif /* CDATATEST_H_ */
