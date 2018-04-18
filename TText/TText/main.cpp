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

char* to_char(std::string str)
{
	char *cstr = new char[str.length() + 1];
	strcpy(cstr, str.c_str());
	
	return cstr;
}

void main()
{	
	TLink::InitMem(100);

	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
	
	TText text;
	char file[] = "C:\\Users\\kutovoj.v\\Desktop\\Text\\TText\\test.txt";

	int inputkey;
	int x = 0, y = 0, free;

	std::string title = "Text Editor";
	std::string tmp;
	std::wstring stemp = s2ws(title);
	LPCWSTR result = stemp.c_str();

	SetConsoleTitle(result);
	SetConsoleOutputCP(1251);

	std::cout
		<< "dwn_arrow - go next header\n"
		<< "up_arrow - go prev\n"
		<< "right_arrow - go inside header\n"
		<< "1 - new header\n" 
		<< "2 - new body\n" 
		<< "3 - new section\n" 
		<< "4 - delete header\n"
		<< "5 - delete body\n"
		<< "6 - save\n"
		<< "7 - print free mem\n"
		<< "0 - help\n"
		<< std::endl;

	text.Read(file);
	text.View();
	gotoxy(0, 0);

	while (true) 
	{
		inputkey = getkey();

		tmp = "";
		switch (inputkey)
		{
		case 38:    // up_arrow - go prev header
			text.goprvlnk();
			clrscr();
			text.View();
			break;
		case 40:    // dwn_arrow - go next header
			text.gonxtlnk();
			clrscr();
			text.View();
			break;
		case 39:    // right_arrow - go inside header
			text.godwnlnk();
			clrscr();
			text.View();
			break;
		case 37:    // left arrow - go outside body
			break;
		case 48:
			std::cout
				<< "\n"
				<< "dwn_arrow - go next header\n"
				<< "up_arrow - go prev\n"
				<< "right_arrow - go inside header\n"
				<< "1 - new header\n"
				<< "2 - new body\n"
				<< "3 - new section\n"
				<< "4 - delete header\n"
				<< "5 - delete body\n"
				<< "6 - save\n"
				<< "7 - view free mem\n"
				<< "8 - clear mem\n"
				<< std::endl;
			break;
		case 49: // 1 - new header 
			Sleep(100);
			clrscr();
			std::cout << "Enter header name\n";
			std::cin >> tmp;
			if (tmp == "") tmp = "NewHeader";
			text.insnxtline(to_char(tmp));
			text.View();
			break;
		case 50: // 2 - new body 
			Sleep(100);
			clrscr();
			std::cout << "Enter body\n";
			std::cin >> tmp;
			if (tmp == "") tmp = "NewBody";
			text.insdwnline(to_char(tmp));
			text.View();
			break;
		case 51: // 3 - new section 
			Sleep(100);
			clrscr();
			std::cout << "Enter section\n";
			std::cin >> tmp;
			if (tmp == "") tmp = "NewSection";
			text.insnxtsection(to_char(tmp));
			text.View();
			break;
		case 52: // 4 - delete header
			clrscr();
			text.delnxt();
			text.View();
			break;
		case 53: // 5 - delete body
			clrscr();
			text.deldwn();
			text.View();
			break;
		case 54: // 6 - save
			text.Save("C:\\Users\\kutovoj.v\\Desktop\\Text\\TText\\testsave.txt");
			break;
		case 55: // 7 - free mem
			clrscr();
			free = TLink::PrintFree(text);
			std::cout << "free mem" << free << std::endl;
			text.View();
			break;
		case 56: // 8 clear mem
			TLink::MemClean(text);
			break;
		}
		Sleep(300);
	}
	_getch();
}