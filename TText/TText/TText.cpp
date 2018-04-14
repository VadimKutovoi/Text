#include "TText.h"

int TText::gonxtlnk()
{
	if (pCurr->pNext != nullptr) {
		st.push(pCurr);
		pCurr = pCurr->pNext;
		return 1;
	}
	else return 0;
}

int TText::godwnlnk()
{
	if (pCurr->pDown != nullptr) {
		st.push(pCurr);
		pCurr = pCurr->pDown;
		return 1;
	}
	else return 0;
}

int TText::goprvlnk()
{
	if (!st.empty()) 
	{
		pCurr = st.top();
		st.pop();
		return 1;
	}
	else return 0;
}

void TText::insnxtline(char* str)
{
	TLink*tl = new TLink(str, pCurr->pNext, nullptr);
	pCurr->pNext = tl;
}

void TText::insnxtsection(char*str)
{
	TLink *p = new TLink(str, nullptr, pCurr->pDown);
	pCurr->pDown = p;
	
}

void TText::insdwnline(char*str)
{
	TLink*tl = new TLink(str, pCurr->pDown, nullptr);
	pCurr->pDown = tl;
}

void TText::delnxt()
{
	TLink*tl = pCurr->pNext;

	if (pCurr->pNext != nullptr) {
		pCurr->pNext = tl->pNext;
		delete tl;
	}
}

void TText::deldwn()
{
	TLink*tl = pCurr->pDown;

	if (pCurr->pDown != nullptr) {
		pCurr->pDown = tl->pDown;
		delete tl;
	}
}

TLink* TText::cpyrec(TLink*tmp)
{
	TLink*pN = nullptr, *pD = nullptr;

	if (tmp->pDown != nullptr)
		pD = cpyrec(tmp->pDown);
	if(tmp->pNext != nullptr)
		pN = cpyrec(tmp->pNext);

	TLink*res = new TLink(tmp->str, pN, pD);
	
	return res;
}

TLink* TText::cpy()
{
	return cpyrec(pFirst);
}

void TText::reset()
{
	pCurr = pFirst;

	while(!st.empty()) st.pop();
	st.push(pCurr);
	
	if (pCurr->pNext != nullptr)
		st.push(pCurr->pNext);
	if (pCurr->pDown != nullptr)
		st.push(pCurr->pDown);
}

bool TText::isend()
{
	return(st.empty());
}

void TText::gonext()
{
	if (!st.empty()) {
		pCurr = st.top();
		st.pop();
	}

	if (pCurr != pFirst)
	{ 
		if (pCurr->pDown != nullptr) 
			st.push(pCurr->pDown);

		if (pCurr->pNext != nullptr)
			st.push(pCurr->pNext);
	}
}

//void TText::gonextlnk()
//{
//	if (pCurr->pDown != nullptr) 
//	{
//		st.push(pCurr->pDown);
//		pCurr = pCurr->pDown;
//		return;
//	}
//	else
//		if (pCurr->pNext != nullptr)
//		{
//			st.push(pCurr->pNext);
//			pCurr = pCurr->pNext;
//			return;
//		}
//}

TLink *TText::ReadRec(std::ifstream& file) 
{
	char buf[80];
	TLink *tmp, *first = nullptr;

	while (!file.eof()) 
	{
		file.getline(buf, 80, '\n');

		if (buf[0] == '}')
			break;
		else if (buf[0] == '{')
			tmp->pDown = ReadRec(file);
		else if (first == nullptr) 
		{
			first = new TLink(buf);
			tmp = first;
		}
		else
		{
			tmp->pNext = new TLink(buf);
			tmp = tmp->pNext;
		}
	}

	return first;
}

void TText::Read(char *fn)
{
	std::ifstream ifs(fn);
	if (fn)
		pCurr = pFirst = ReadRec(ifs);
}


void TText::View()
{
	lvl = 0;
	viewText(pFirst);
}

void TText::viewText(TLink *ptr)
{
	if (ptr == pCurr) {
		
		HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(Console, (WORD)((0 << 4) | 4));

		std::cout << "_";

		Console = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(Console, (WORD)((0 << 4) | 15));

	}

	if (ptr) {
		for (int i = 0; i < lvl; i++)
			std::cout << "\t";
		
		std::cout << ptr->getStr() << std::endl;
		lvl++;
		viewText(ptr->getPDown());
		lvl--;
		viewText(ptr->getPNext());
	}
}

void TText::SaveText(TLink* tmp, std::ofstream& f)
{
	f << tmp->str << '\n';
	if (tmp->pDown != NULL)
	{
		f << "{\n";
		SaveText(tmp->pDown, f);
		f << "}\n";
	}
	if (tmp->pNext != NULL)
		SaveText(tmp->pNext, f);
}


void TText::Save(char* fn)
{
	std::ofstream ofs(fn, std::ios::in);
	if (ofs.is_open())
	{
		SaveText(pFirst, ofs);
		ofs.close();
	}
}