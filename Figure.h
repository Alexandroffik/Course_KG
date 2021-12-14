#pragma once

#include <windows.h>
#include "matrix.h"
#include "bitmap.h"
#include "function_draw.h"

#define PI 3.141592

// положение 1 окна
enum class DIM_BMP_ONE {
	left_margin		=	10,
	top_margin		=	10,
	width			=	600,
	height			=	610
};

// положение 2 окна
enum class DIM_BMP_TWO {
	left_margin		=	616,
	top_margin		=	10,
	width			=	600,
	height			=	610
};

enum class COL_BMP {
	// цвет фона
	clear	=	RGB_BMP(255, 255, 255),

	// цвет тени
	shadow	=	RGB_BMP(30, 30, 30),
};
enum class COL_PYR {

	// цвет каждой грани
	zero	=	RGB_BMP(13, 180, 70),
	one		=	RGB_BMP(50, 200, 200),
	two		=	RGB_BMP(123, 104, 238),
	three	=	RGB_BMP(255, 165, 31),
	four	=	RGB_BMP(244, 66, 140)
};

// число треугольников
// квадрат -> 2 треугольника
enum class NUM_VER {
	pyr_1	=	 4,
	pyr_2	=	 6
};

const double	ANGLE		=	0.05;
const int		STEP		=	6;
const double	ZOOM_PLUS	=	1.25;
const double	ZOOM_MINUS	=	1 / ZOOM_PLUS;

class figure {
public:
	enum { dim = 4 };
	figure(BitMap *bmp, size_t numVer);
	~figure();

	void rotate(char, char);
	void move(char, char);
	void zoom(char);

	virtual void SetBitMap() = 0;
	virtual void ClrBitMap() = 0;

	void refresh();
protected:
	double sinAlpha;
	double cosAlpha;
	
	vector<double> center;
	void SetCenter();

	// точки самого объекта
	vector<double> *Ver;

	// точки в проекции экрана
	vector<double> *V;
	size_t numVer;

	matrix<double> ROTATE;
	matrix<double> ZOOM;
	
	matrix<double> PR;
	void SetPR();

	BitMap *bmp;

	int offset;

	virtual void SetShadow(COLORREF c) = 0;
};