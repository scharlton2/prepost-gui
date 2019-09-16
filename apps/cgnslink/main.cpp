#include <cgnslib.h>
#include <iriclib.h>

#include <iostream>
#include <sstream>

int main(int argc, char* argv[])
{
	int fn, ier, progress, invalidDataId;

	ier = cg_open("output.cgn", CG_MODE_MODIFY, &fn);
	ier = cg_iRIC_Init(fn);

	ier = cg_iRIC_Link_Solutions(fn, &progress, &invalidDataId);
	
	ier = cg_close(fn);
}
