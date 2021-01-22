
#include "pch.h"
#include <stdio.h>

void FindOriginalParentFromFakeModalDialog(HWND dialogHwnd) {
	WCHAR windowName[MAX_PATH];
	HWND originalParent = 0;

	GetClassNameW(dialogHwnd, windowName, MAX_PATH);
	wprintf(L"current window className is %ls \n", windowName);

	//undocumented value (from ieframe.dll)
	originalParent = GetPropW(dialogHwnd, L"FakeModalPartnerFrame");

	GetWindowTextW(originalParent, windowName, MAX_PATH);
	wprintf(L"parent window text is %ls , originalhwnd is %x\n", windowName, (DWORD)originalParent);
}

int main(int argc,char** argv)
{
	HWND hwnd = 0;
	scanf("%x",&hwnd); //('Alternate Modal Top Most' hwnd)
	FindOriginalParentFromFakeModalDialog(hwnd);
	return 0;
}
