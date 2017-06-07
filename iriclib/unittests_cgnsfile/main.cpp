#include "cases.h"

#include <iostream>

int main(int argc, char* argv[])
{
	case_InitSuccess();
	case_InitFail();

	case_InitReadSuccess();
	case_InitReadFail();

	case_InitOptionCheck();

	case_InitCC();

	case_CheckLock();
	case_CheckCancel();

	case_CalcCondRead();
	case_CalcCondWrite();

	case_BcRead();
	case_BcWrite();

	case_Complex();

	case_GridRead();
	case_GridReadFunc();
	case_GridWrite();

	case_SolStartEnd();

	case_SolWriteStd();
	case_SolWriteDivide();

	return 0;
}