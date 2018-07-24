#include <cgnslib.h>
#include <iriclib.h>

#include <iostream>
#include <sstream>

int main(int argc, char* argv[])
{
	int fn, ier, progress, invalidDataId;
	int maxid = -1;

	if (argc > 1) {
		std::istringstream ss;
		ss.str(argv[1]);
		ss >> maxid;
	}
	
	ier = cg_open("Case1.cgn", CG_MODE_MODIFY, &fn);
	ier = cg_iRIC_Init(fn);

	ier = cg_iRIC_Combine_Solutions(fn, &progress, &invalidDataId, maxid);
	
	ier = cg_close(fn);
}
