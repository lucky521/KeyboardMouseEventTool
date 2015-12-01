
#include "hook.h"
using namespace std;
HHOOK g_KeybdHook = NULL;
HHOOK g_MouseHook = NULL;
HINSTANCE g_hInstance = NULL;


/*
	LowLevelKeyboardProc callback function
	https://msdn.microsoft.com/en-us/library/windows/desktop/ms644985(v=vs.85).aspx
	low-level keyboard input event structure
	https://msdn.microsoft.com/en-us/library/windows/desktop/ms644967(v=vs.85).aspx
*/
LRESULT CALLBACK LowLevelKeybdProc(int aCode, WPARAM wParam, LPARAM lParam)
{
	//cout<<"keyboard event "<<aCode<<endl;
	KBDLLHOOKSTRUCT kbdStruct;

	if (aCode >= 0)
    {
		kbdStruct = *((KBDLLHOOKSTRUCT*)lParam);
        if (wParam == WM_KEYDOWN)
        {
			/*
			printf("key down event %x ",kbdStruct.vkCode);
			unsigned short key;
			scan2ascii(kbdStruct.scanCode, &key);
			printf("%c\n",key); 
			*/
				printf("key down event %s, %s \n",\
				hhb_vkey_list[kbdStruct.vkCode].name,\
				hhb_vkey_list[kbdStruct.vkCode].description);
			
        }
		else if (wParam == WM_SYSKEYDOWN)
		{
			printf("syskey down event %s, %s \n", \
				hhb_vkey_list[kbdStruct.vkCode].name,\
				hhb_vkey_list[kbdStruct.vkCode].description);
			
		}
		/*
		else if (wParam == WM_KEYUP)
		{
		    kbdStruct = *((KBDLLHOOKSTRUCT*)lParam);
			printf("keyboard event %x ",kbdStruct.vkCode);
			unsigned short key;
			scan2ascii(kbdStruct.scanCode, &key);
			printf("%c\n",key); 
		}
		else if (wParam == WM_SYSKEYUP)
		{
		    kbdStruct = *((KBDLLHOOKSTRUCT*)lParam);
			printf("keyboard event %x ",kbdStruct.vkCode);
			unsigned short key;
			scan2ascii(kbdStruct.scanCode, &key);
			printf("%c\n",key); 
		}*/
    }

	return CallNextHookEx(NULL, aCode, wParam, lParam);;
}


/*
	LowLevelMouseProc callback function
	https://msdn.microsoft.com/en-us/library/windows/desktop/ms644986(v=vs.85).aspx
	MOUSEHOOKSTRUCT structure
	https://msdn.microsoft.com/en-us/library/windows/desktop/ms644970(v=vs.85).aspx
*/
LRESULT CALLBACK LowLevelMouseProc(int aCode, WPARAM wParam, LPARAM lParam)
{
	//cout<<"mouse event "<<aCode<<endl;
	MSLLHOOKSTRUCT mouseStruct;
	if (aCode >= 0)
    {
		mouseStruct = *((MSLLHOOKSTRUCT*)lParam);
        if (wParam == WM_LBUTTONDOWN)
        {
			printf("mouse left down event\n");
        }
		else if (wParam == WM_RBUTTONDOWN)
		{
			printf("mouse left down event\n");
		}
		else if (wParam == WM_MOUSEWHEEL)
		{
			if(HIWORD(mouseStruct.mouseData)>0)
				printf("mouse scroll forward event\n");
			else
				printf("mouse scroll backward event\n");
		}
		else if (isMousemove && wParam == WM_MOUSEMOVE)
		{
			POINT pt = reinterpret_cast<MSLLHOOKSTRUCT*>(lParam)->pt;
			printf("mouse move event location (%d, %d)\n", pt.x, pt.y);
		}
	}
	return CallNextHookEx(NULL, aCode, wParam, lParam);;
}



int unhook()
{
	UnhookWindowsHookEx(g_KeybdHook);
	UnhookWindowsHookEx(g_MouseHook);
	return 0;
}

int sethook()
{
	bool problem_activating_hooks = false;
	if (!g_KeybdHook && isKey) 
	{
		if (   !(g_KeybdHook = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeybdProc, g_hInstance, 0))   )
			problem_activating_hooks = true;
			cout<<"hook keyboard"<<endl;
	}

	if (!g_MouseHook && isMouse)
	{
		if (   !(g_MouseHook = SetWindowsHookEx(WH_MOUSE_LL, LowLevelMouseProc, g_hInstance, 0))   )
			problem_activating_hooks = true;
			cout<<"hook mouse"<<endl;
	}
	return 0;
}
