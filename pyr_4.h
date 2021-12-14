#pragma once
#include "Figure.h"

class pyr_4 : public figure {
public:
	pyr_4(BitMap* bmp);
	void ClrBitMap();
	void SetBitMap();
private:
	void SetShadow(COLORREF c);
};
