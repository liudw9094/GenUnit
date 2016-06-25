#include <string>
#include <vector>
#include "CCombGen.h"

using namespace std;

int main(int argn, char* argv[])
{
	vector<string> vargs;
	for(int i = 0; i < argn; ++i)
		vargs.push_back(string(argv[i]));
	CCombGen gen(vargs);
	return gen.run();
}
