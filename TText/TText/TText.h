#pragma once
#include "TLink.h"
#include <stack>
#include <fstream>
#include <iostream>
#include <Windows.h>

class TText
{
	TLink*pFirst, *pCurr;
	std::stack<TLink*> st;
	int lvl;

public:
	TText(){}
	
	

	/*void gonextlnk();*/
	int gonxtlnk(); //Сдвиг указателя pNext вниз
	int godwnlnk(); //Сдвиг указателя pDown вниз
	int goprvlnk(); //Возврат сдвинутого указателя на шаг назад
	void insnxtline(char*str); //Вставить строку по указателю pNext
	void insnxtsection(char*str); 
	void insdwnline(char*str); //Вставить строку по указателю pDown
	void delnxt(); //Удалить строку по указателю pNext
	void deldwn(); //Удалить строку по указателю pDown
	void MarkCurr() { pCurr->flag = true; }

	TLink* cpyrec(TLink*tmp); //Рекурсивное копирование 
	TLink* cpy(); //Возвращает результат cpyrec для указателя pFirst

	void reset(); 
	bool isend();
	void gonext();

	TLink*ReadRec(std::ifstream& file);
	void Read(char *fn);

	void View();
	void viewText(TLink *ptr);
	void Save(char* fn);
	void SaveText(TLink* tmp, std::ofstream& f);


};