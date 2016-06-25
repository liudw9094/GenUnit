/*
 * CFileReader.h
 *
 *  Created on: Dec 5, 2015
 *      Author: ldw
 */

#ifndef CFILEREADER_H_
#define CFILEREADER_H_

#include <string>
#include <vector>

class CFileReader {
private:
	std::string m_filepath;
	std::string m_head;
	std::vector<std::string> m_testCases;
	std::string m_end;
	bool m_bFileValid;
public:
	CFileReader(const std::string& filepath);
	~CFileReader();

	inline const std::string& filepath() const {return m_filepath;}
	inline const std::string& head() const {return m_head;}
	inline const std::vector<std::string> testCases() const {return m_testCases;}
	inline const std::string end() const {return m_end;}
	inline bool bFileValid() const {return m_bFileValid;}
private:
	void readFile();
	bool getHead(const std::vector<char>& content, size_t &nCur);
	bool getTestCases(const std::vector<char>& content, size_t &nCur);
	bool getOneTestCase(const std::vector<char>& content, size_t &nCur);
	bool getEnd(const std::vector<char>& content, size_t &nCur);
};

#endif /* CFILEREADER_H_ */
