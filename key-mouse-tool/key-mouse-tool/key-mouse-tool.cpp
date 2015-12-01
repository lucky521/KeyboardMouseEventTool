// key-mouse-tool.cpp : Defines the entry point for the console application.
//

#include "hook.h"

int main()
{
	sethook();
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {

    }
	unhook();
	return 0;
}

