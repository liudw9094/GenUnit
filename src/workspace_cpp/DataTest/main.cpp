#include <string>
#include <vector>
#include "CDataTest.h"

using namespace std;

int main(int argn, char* argv[])
{
	vector<string> vargs;
	for(int i = 0; i < argn; ++i)
		vargs.push_back(string(argv[i]));
	CDataTest app(vargs);
	return app.run();
}
