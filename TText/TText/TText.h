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

	/*void gonextlnk();*/
	int gonxtlnk(); //����� ��������� pNext ����
	int godwnlnk(); //����� ��������� pDown ����
	int goprvlnk(); //������� ���������� ��������� �� ��� �����
	void insnxtline(char*str); //�������� ������ �� ��������� pNext
	void insnxtsection(char*str); 
	void insdwnline(char*str); //�������� ������ �� ��������� pDown
	void delnxt(); //������� ������ �� ��������� pNext
	void deldwn(); //������� ������ �� ��������� pDown
	void MarkCurr()
	{
		pCurr->flag = true;
	}

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


};