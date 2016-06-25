/*
 * CGATask.cpp
 *
 *  Created on: Dec 4, 2015
 *      Author: ldw
 */

#include "CGATask.h"
#include <unistd.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <iostream>
#include <limits.h>
#include <Utils.h>
#include "COrgGen.h"

using namespace std;


CGATask::CGATask(const COrgGen& gen, int nIndex) :
		m_srcDir(gen.srcDir()),
		m_binDir(gen.binDir()),
		m_seedOrin(gen.seed()),
		m_nIndex(nIndex),
		m_seed(rand())
{
	// TODO Auto-generated constructor stub

}

CGATask::~CGATask() {
	// TODO Auto-generated destructor stub
}


int CGATask::run() {
	//execl("");
	char str[256];
	string outputdir = "output/t";
	sprintf(str,"%d",m_nIndex);
	outputdir += str;
	string evoPath= getDirectory(getexepath()) + "/evo/evosuite-1.0.1.jar";
	string command = "java -jar ";
	command += evoPath;
	command += string() + " -projectCP \"" + m_srcDir + "\"";
	command += string() + " -target \"" + m_binDir + "\"";
	command += string() + " -seed ";
	sprintf(str,"%d",m_seed);
	command += str;
	//command += string() + " -base_dir \"" + outputdir + "\"";
	//command += string() + " > "  + outputdir + "/evo.txt";
	string cmdMkDir = "mkdir \"";
	cmdMkDir += outputdir + "\"";

	string commandMkDir1 = "mkdir output";
	string commandMkDir2 = cmdMkDir.c_str();
	string commandCD = string("cd ") + outputdir;
	string commandCDandCommand = commandCD + " && " + command;
#ifdef _DEBUG
	cout<<"commands:\n"
			<<commandMkDir1<<endl<<commandMkDir2<<endl
			<<commandCDandCommand<<endl<<endl;
#endif
	system(commandMkDir1.c_str());
	system(commandMkDir2.c_str());
	safeinfo();
	int rt = system(commandCDandCommand.c_str());
	if(rt == 0)
	{}
	return rt;
}


void CGATask::safeinfo()
{

}
