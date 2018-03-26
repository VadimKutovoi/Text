#pragma once
#include "TLink.h"
#include <stack>
#include <fstream>
#include <iostream>

class TText
{
	TLink*pFirst, *pCurr;
	std::stack<TLink*> st;
	int lvl;

public:
	TText(){}
	
	//������ ����������.��������

	void gonext();
	int gonxtlnk(); //����� ��������� pNext ����
	int godwnlnk(); //����� ��������� pDown ����
	int goprvlnk(); //������� ���������� ��������� �� ��� �����
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

	//������ � ������

	TLink*ReadRec(std::ifstream& file);
	void Read(char *fn);

	//�����������

	void View();
	void viewText(TLink *ptr);

	//������ ���������.�������� ������

	void* operator new(size_t s);
	void operator delete(void*ptr);
	static void initmemory(size_t s);
	static void cleanmemory(TText&t);
};