/*
 * CTRJudge.h
 *
 *  Created on: Dec 10, 2015
 *      Author: ldw
 */

#ifndef CTRJUDGE_H_
#define CTRJUDGE_H_

#include <string>
#include <vector>

class CTRJudge {
private:
	struct SUITEREPORT
	{
		std::string suitepath;
		std::vector<std::string> coverageReportPaths;
		double lfLineCoverage;
		double lfTotalLine;
		double lfFinalScore;
	};
	const std::vector<std::string>& m_args;

	enum MODE
	{
		MODE_JUDEGE,
		MODE_EVALUATION
	}m_mode;
	std::string m_groupDir;
	std::string m_dstDir;
	int	m_nTopNum;
	std::vector<std::string> m_vsuitePaths;
	std::vector<SUITEREPORT> m_vsuiteReports;
public:
	CTRJudge(const std::vector<std::string>& args);
	~CTRJudge();

	int run();
private:
	bool parseCommands();
	void showCommands();
	int doCommands();
	bool searchTestSuites();
	int getReportInfos(double &lfTotalLine, double &lfLineCov);
	bool getReportInfo(const std::string& suitepath);
	int doJudge();
	int saveResults();
};

#endif /* CTRJUDGE_H_ */