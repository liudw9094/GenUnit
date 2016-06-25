#include <iostream>
#include <string>
#include <vector>
#include "COrgGen.h"

using namespace std;

int main(int argn, char* argv[])
{
	vector<string> vargs;
	for(int i = 0; i < argn; ++i)
		vargs.push_back(string(argv[i]));
	COrgGen gen(vargs);
	return gen.run();
}
