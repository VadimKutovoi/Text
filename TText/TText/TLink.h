#pragma once
#include <cstdlib>
#include <cstring>
class TLink;

struct TMem { TLink*pFirst, *pFree, *pLast;};

class TLink
{
public:
	char str[80]; 
	TLink*pNext, *pDown;
	static TMem memory;

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

	~TLink(){}
};