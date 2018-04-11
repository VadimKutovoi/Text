#include <windows.h>
#include <conio.h>
#include <iostream>
#include "mystructures.h"
#include "TText.h"

TMem TLink::mem;

void clrscr(void)
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!Console) return;

	CONSOLE_SCREEN_BUFFER_INFO buf;
	GetConsoleScreenBufferInfo(Console, &buf);

	DWORD Count;

	COORD zpos;
	zpos.X = 0;
	zpos.Y = 0;

	FillConsoleOutputCharacter(Console, ' ', buf.dwSize.X * buf.dwSize.Y, zpos, &Count);
	SetConsoleCursorPosition(Console, zpos);
}

void main()
{	
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
	
	TText text;
	char file[] = "C:\\Users\\\kutovoj.v\\Desktop\\Text\\Text\\TText\\test.txt";

	int inputkey;
	int x = 0, y = 0;

	std::string title = "Text Editor";
	std::wstring stemp = s2ws(title);
	LPCWSTR result = stemp.c_str();

	SetConsoleTitle(result);
	SetConsoleOutputCP(1251);

	std::cout << "-> - ins dwn line\n" << "< - ins next line\n" << "1 - del next\n" << "2 - del down\n" << "3 - go next\n" << "4 - go down\n" << std::endl;
	text.Read(file);
	text.View();
	gotoxy(0, 0);

	while (true) 
	{
		inputkey = getkey();

		switch (inputkey)
		{
		case 38:    // key up
			y--;
			text.goprvlnk();
			gotoxy(x, y);
			break;
		case 40:    // key down
			y++;
			text.gonxtlnk();
			gotoxy(x, y);
			break;
		case 39:    // key right
			//x++;
			//gotoxy(x, y);
			clrscr();
			text.insnxtline("nextline");
			text.View();
			gotoxy(x, y);
			break;
		case 37:    // key left
			//x--;
			//gotoxy(x, y);
			clrscr();
			text.insdwnline("dwnline");
			text.View();
			gotoxy(x, y);
			
			break;
		case 49: // 1 del next
			clrscr();
			text.delnxt();
			text.View();
			gotoxy(x, y);
			break;
		case 50: // 2 del dwn
			clrscr();
			text.deldwn();
			text.View();
			gotoxy(x, y);
			break;
		case 51: //3 
			text.gonxtlnk();
			break;
		case 52: //4
			text.godwnlnk();
			break;
		}
		Sleep(300);
	}
	_getch();
}