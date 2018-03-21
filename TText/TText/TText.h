#pragma once
#include "TLink.h"
#include <stack>

class TText
{
	TLink*pFirst, *pCurr;
	std::stack<TLink*> st;

public:
	TText(){}
	
	//методы добавления.удаления

	void gonxtlnk(); //Сдвиг указателя pNext вниз
	void godwnlnk(); //Сдвиг указателя pDown вниз
	void goprvlnk(); //Возврат сдвинутого указателя на шаг назад
	void insnxtline(char*str); //Вставить строку по указателю pNext
	void insnxtsection(char*str); 
	void insdwnline(char*str); //Вставить строку по указателю pDown
	void delnxt(); //Удалить строку по указателю pNext
	void deldwn(); //Удалить строку по указателю pDown
	
	//методы копирования

	TLink* cpyrec(TLink*tmp); //Рекурсивное копирование 
	TLink* cpy(); //Возвращает результат cpyrec для указателя pFirst

	//методы итерирования

	void reset(); 
	bool isend();
	void gonext();

	//Методы выделения.очищения памяти

	void* operator new(size_t s);
	void operator delete(void*ptr);
	static void initmemory(size_t s);
	static void cleanmemmory(TText&t)
};