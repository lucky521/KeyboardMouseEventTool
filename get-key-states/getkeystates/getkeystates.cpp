// getkeystates.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

using namespace std;

#define OUTFILENAME "ModifierKey-states.txt" 


void modifier_key(int key, char *name)
{
	ofstream myfile;
	myfile.open (OUTFILENAME, ios::app);
	SHORT state = 0;
	state = GetKeyState(key);
	//printf("state=0x%08x\n", state);

	bool pressed = ( state & 0x8000 ) ? true : false;
	bool toggled = ( state & 0x0001 ) ? true : false;

	myfile << name << "\t state: ";
	printf("%s \t state: ", name);
	if(pressed) 
	{
		myfile << "pressed ";
		printf("pressed ");
	}
	if(toggled) 
	{
		myfile << "toggled";
		printf("toggled");
	}
	myfile << "\n";
	printf("\n");
	
	myfile.close();
	return;
}


void keyboard()
{
	BYTE  kbstate[256];
	if (!GetKeyboardState(kbstate))
		printf("GetKeyboardState failed!!!\n ");

	for(int i=0;i<256;i++)
	{
		printf("%x ", kbstate[i]);
	}

	return;
}


int _tmain(int argc, _TCHAR* argv[])
{
	
	ofstream myfile;
	myfile.open(OUTFILENAME, ios::app);

	time_t nowtime;
	nowtime = time(NULL);
	struct tm *local;
	local=localtime(&nowtime); 
	char buf[80];
	strftime(buf,80,"%a, %d %b %Y %H:%M:%S",local);
	
	cout << buf << endl;
	myfile << endl;
	myfile <<buf<<endl;
	myfile.close();

	modifier_key(VK_LSHIFT, "VK_LSHIFT");
	modifier_key(VK_RSHIFT, "VK_RSHIFT");
	modifier_key(VK_LCONTROL, "VK_LCONTROL");
	modifier_key(VK_RCONTROL, "VK_RCONTROL");
	modifier_key(VK_LMENU, "VK_LMENU"); // alt
	modifier_key(VK_RMENU, "VK_RMENU");
	modifier_key(VK_LWIN, "VK_LWIN");
	modifier_key(VK_RWIN, "VK_RWIN");


	printf("\nDone.\n");


	//keyboard();


	//getchar();
	return 0;
}

