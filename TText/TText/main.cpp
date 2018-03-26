#include <windows.h>
#include <conio.h>
#include "mystructures.h"
#include "TText.h"

TMem TLink::memory;

void main()
{	
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
	
	TText text;
	char file[] = "C:\\Users\\sirku\\Desktop\\GitProjects\\Text\\TText\\test.txt";

	int inputkey;
	int x = 0, y = 0;

	std::string title = "Text Editor";
	std::wstring stemp = s2ws(title);
	LPCWSTR result = stemp.c_str();

	SetConsoleTitle(result);
	SetConsoleOutputCP(1251);

	text.Read(file);
	text.View();
	gotoxy(0, 0);

	while (true) 
	{
		inputkey = getkey();

		switch (inputkey)
		{
		case 38:    // key up
			if (y != 0)
			{
				y--;
				text.goprvlnk();
				gotoxy(x, y);
			}
			break;
		
		case 40:    // key down
			y++;
			gotoxy(x, y);
			break;
		
		case 39:    // key right
			x++;
			gotoxy(x, y);
			break;
		
		case 37:    // key left
			if (x != 0)
			{
				x--;
				gotoxy(x, y);
			}
			break;
		}
		Sleep(150);
	}
	_getch();
}