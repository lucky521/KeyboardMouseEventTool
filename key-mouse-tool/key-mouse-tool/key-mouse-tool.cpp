// key-mouse-tool.cpp : Defines the entry point for the console application.
//

#include "hook.h"
#include "deviceInfo.h"
int main()
{
	deviceInfo device;
	device.showInfo();

	/*
	sethook();
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {

    }
	unhook();
	*/
	return 0;
}
