#include <windows.h>

extern  "C" _declspec(dllexport) UINT Summa(UINT a, UINT b)
{
	return a + b;
}