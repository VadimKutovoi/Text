#pragma once
#include <cstdlib>
#include <cstring>

class TText;
class TLink;

struct TMem { TLink*pFirst, *pFree, *pLast;};

class TLink
{
public:
	char str[80]; 
	TLink*pNext, *pDown;
	static TMem mem;
	bool flag;

	TLink(char*s = nullptr, TLink*pN = nullptr, TLink*pD = nullptr)
	{
		pNext = pN;
		pDown = pD;

		if (s == nullptr)
		{
			str[0] = '\o';
		}
		else
			strcpy(str, s);
	}

	char* getStr()
	{
	    return str;
	}

	TLink* getPDown()
	{
		return pDown;
	}

	TLink* getPNext()
	{
		return pNext;
	}

	static void InitMem(size_t s);
	static void MemClean(TText &t);
	static int PrintFree(TText &t);
	void* operator new(size_t s);
	void operator delete(void*p);

	~TLink(){}
};