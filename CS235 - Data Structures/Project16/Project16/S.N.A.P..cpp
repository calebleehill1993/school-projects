#include <iostream>
#include <string>
#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif

#include "Cdh.h"
#include "Cr.h"
#include "Csg.h"
#include "Snap.h"

using namespace std;

int main(int argc, char *argv[])
{
	VS_MEM_CHECK               // enable memory leak check

	return 0;
}