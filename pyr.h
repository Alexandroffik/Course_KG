#pragma once
#include "Figure.h"

class pyr : public figure {
public:
	pyr(BitMap *bmp);
	void ClrBitMap();
	void SetBitMap();
private:
	void SetShadow(COLORREF c);
};
