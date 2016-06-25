/*
 * CCoverageReportReader.cpp

 *
 *  Created on: Dec 10, 2015
 *      Author: ldw
 */
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <Utils.h>
#include "CCoverageReportReader.h"

using namespace std;

CCoverageReportReader::CCoverageReportReader(const std::string& filepath) :
		m_filepath(filepath), m_lfCoveredNum(-1.0), m_lfTotalNum(-1.0), m_bFileValid(false)
{
	// TODO Auto-generated constructor stub

}

CCoverageReportReader::~CCoverageReportReader() {
	// TODO Auto-generated destructor stub
}

void CCoverageReportReader::readFile()
{
	vector<char> fileContent = getFileContent(m_filepath);
	size_t cur = 0;
	if(!GetCoverageInfo(fileContent, cur))
		return;
	m_bFileValid = true;
}

bool CCoverageReportReader::GetCoverageInfo(const std::vector<char>& content, size_t &nCur)
{
	string lines;
	enum STATE
	{
		PRE_COVTEXT,
		COVTEXT
	} state = PRE_COVTEXT;
	while(nCur < content.size())
	{
		string line = getLine(content, nCur);
		switch(state)
		{
		case PRE_COVTEXT:
			if(line.find("COVERAGE BREAKDOWN BY PACKAGE:") != string::npos)
			{
				state = COVTEXT;
				m_lfCoveredNum = m_lfTotalNum = 0.0;
			}
			break;
		case COVTEXT:
			if(line.find("org.ldw.RunTest") != string::npos)
				break;
			double lfCoveredNum, lfTotalNum;
			if(GetLineCoverageInfoPerPackage(line, lfCoveredNum, lfTotalNum))
			{
				m_lfCoveredNum += lfCoveredNum;
				m_lfTotalNum += lfTotalNum;
			}
		}
	}
	return state != PRE_COVTEXT;
}

bool CCoverageReportReader::GetLineCoverageInfoPerPackage(const std::string& line, double &lfCoveredNum, double &lfTotalNum)
{

	// "100% (4/4)	96%  (24/25)	91%  (307/336)	94%  (102.1/109)	org.ldw"
	string lineCopy = line;
	for(size_t pos=0; (pos = lineCopy.find("\t"), pos) != string::npos; )
	{
		lineCopy.replace(pos, 1, string(" "));
	}
	for(size_t pos=0; (pos = lineCopy.find("  ")) != string::npos; )
	{
		for(size_t pos1=pos; (pos1 = lineCopy.find("  "), pos1) != string::npos; )
			lineCopy.erase(lineCopy.begin() + pos);
	}

	// "100% (4/4) 96% (24/25) 91% (307/336) 94% (102.1/109) org.ldw"
	size_t posLineCov = lineCopy.rfind(" ");
	if(posLineCov == string::npos)
		return false;
	posLineCov = lineCopy.rfind(" ", posLineCov - 1);
	if(posLineCov == string::npos)
		return false;
	posLineCov+=2;
	// "100% (4/4) 96% (24/25) 91% (307/336) 94% (102.1/109) org.ldw"
	//                                            ^
	string linePos = (lineCopy.begin() + posLineCov).base();
	return sscanf(linePos.c_str(), "%lf/%lf", &lfCoveredNum, &lfTotalNum) == 2;
}


