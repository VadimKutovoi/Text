#include "TText.h"

void TText::gonxtlnk()
{
	if (pCurr->pNext != nullptr) {
		st.push(pCurr);
		pCurr = pCurr->pNext;
	}
}

void TText::godwnlnk()
{
	if (pCurr->pDown != nullptr) {
		st.push(pCurr);
		pCurr = pCurr->pDown;
	}
}

void TText::goprvlnk()
{
	if (!st.empty()) 
	{
		pCurr = st.top();
		st.pop();
	}
}

void TText::insnxtline(char*str)
{
	TLink*tl = new TLink(str, pCurr->pNext, nullptr);
	pCurr->pNext = tl;
}

void TText::insnxtsection(char*str)
{
	
	
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
	pCurr = st.top();
	st.pop();
	
	if (pCurr != pFirst)
	{
		if (pCurr->pNext != nullptr)
			st.push(pCurr->pNext);
		if (pCurr->pDown != nullptr)
			st.push(pCurr->pDown);
	}
}
