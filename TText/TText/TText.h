#pragma once
#include "TLink.h"
#include <stack>

class TText
{
	TLink*pFirst, *pCurr;
	std::stack<TLink*> st;

public:
	TText(){}
	
	//������ ����������.��������

	void gonxtlnk(); //����� ��������� pNext ����
	void godwnlnk(); //����� ��������� pDown ����
	void goprvlnk(); //������� ���������� ��������� �� ��� �����
	void insnxtline(char*str); //�������� ������ �� ��������� pNext
	void insnxtsection(char*str); 
	void insdwnline(char*str); //�������� ������ �� ��������� pDown
	void delnxt(); //������� ������ �� ��������� pNext
	void deldwn(); //������� ������ �� ��������� pDown
	
	//������ �����������

	TLink* cpyrec(TLink*tmp); //����������� ����������� 
	TLink* cpy(); //���������� ��������� cpyrec ��� ��������� pFirst

	//������ ������������

	void reset(); 
	bool isend();
	void gonext();

	//������ ���������.�������� ������

	void* operator new(size_t s);
	void operator delete(void*ptr);
	static void initmemory(size_t s);
	static void cleanmemmory(TText&t)
};