#pragma once
#pragma comment (lib, "Setupapi.lib")  // to resolve "unresolved external symbol "
#include <stdio.h>
#include <windows.h>
#include <setupapi.h>
#include <devguid.h>
#include <regstr.h>
class deviceInfo
{
public:
	deviceInfo(void);
	~deviceInfo(void);
	void deviceInfo::PrintLastError (DWORD errCode);
	int showInfo();
};

