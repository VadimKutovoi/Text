#include "TLink.h"
#include "TText.h"

void TLink::InitMem(size_t s)
{
	mem.pFirst = (TLink*) new char[sizeof(TLink)*s];
	mem.pFree = mem.pFirst;
	mem.pLast = mem.pFirst + (s - 1);
	TLink* tmp = mem.pFree;
	for (int i = 0; i < s - 1; i++)
	{
		tmp->pNext = tmp + 1;
		tmp++;
	}
	mem.pLast->pNext = nullptr;
}

void TLink::MemClean(TText &t)
{
	for (t.reset(); !t.isend(); t.gonext())
		t.MarkCurr();
	TLink* tmp;
	tmp = mem.pFree;
	while (tmp != mem.pLast)
	{
		tmp->flag = true;
		tmp = tmp->pNext;
	}
	tmp->flag = true;
	tmp = mem.pFirst;
	while (tmp != mem.pLast)
	{
		if (!tmp->flag)
		{
			TLink* buf = mem.pFree;
			mem.pFree = tmp;
			mem.pFree->pNext = buf;
		}
		tmp->flag = false;
		tmp = tmp++;
	}
	if (!tmp->flag)
	{
		TLink* buf = mem.pFree;
		mem.pFree = tmp;
		mem.pFree->pNext = buf;
	}
	tmp->flag = false;
}

int TLink::PrintFree(TText &t)
{
	int result = 0;
	TLink* tmp = mem.pFree;
	while (tmp != mem.pLast)
	{
		result++;
		tmp = tmp->pNext;
	}
	result++;
	return result;
}

void* TLink::operator new(size_t s)
{
	TLink* tmp = mem.pFree;
	if (mem.pFree != nullptr)
		mem.pFree = mem.pFree->pNext;
	return tmp;
}

void TLink::operator delete(void*p)
{
	TLink*tmp = (TLink*)p;
	tmp->pNext = mem.pFree;
	mem.pFree = tmp;
}

