#include "pyr.h"

//Отрисовка фигуры
pyr::pyr(BitMap *bmp) : figure(bmp, (size_t)(NUM_VER::pyr_1)) {

	Ver[0] = { 130.0, 130.0, 130.0, 1.0 };
	Ver[1] = { 230.0, 130.0, 130.0, 1.0 };
	Ver[2] = { 180.0, 230.0, 130.0, 1.0 };
	Ver[3] = { 180.0, 163.3, 230.0, 1.0 };

	SetCenter();
	SetPR();
	SetShadow(COLORREF(COL_BMP::shadow));
	SetBitMap();
}

void pyr::ClrBitMap() {

	paint_trinagle(bmp, V[0], V[1], V[2], COLORREF(COL_BMP::clear));
	paint_trinagle(bmp, V[1], V[2], V[3], COLORREF(COL_BMP::clear));
	paint_trinagle(bmp, V[0], V[1], V[3], COLORREF(COL_BMP::clear));
	paint_trinagle(bmp, V[0], V[2], V[3], COLORREF(COL_BMP::clear));

	SetShadow(COLORREF(COL_BMP::clear));
}
void pyr::SetShadow(COLORREF c) {
	
	size_t i;
	
	vector<double> tmp;

	// Сохраняем точки объекта и устанавливаем их y в y плоскости тени
	for (i = 0; i < numVer; ++i) {

		tmp.push_back(Ver[i][1]);

		Ver[i][1] = offset;

	}

	// проецируем тень
	SetPR();

	// рисуем тень
	paint_trinagle(bmp, V[0], V[1], V[2], c);
	paint_trinagle(bmp, V[1], V[2], V[3], c);
	paint_trinagle(bmp, V[0], V[1], V[3], c);
	paint_trinagle(bmp, V[0], V[2], V[3], c);

	// восстанавлиаем оригинальные точки
	for (i = 0; i < numVer; ++i) {

		Ver[i][1] = tmp[i];

	}

	SetPR();

}
void pyr::SetBitMap() {
	int i, j, k;
	int mas[4] = { 0, 1, 2, 3 };

	double swp;
	double center[4];
	center[0] = center_z(V[0], V[1], V[2]);
	center[1] = center_z(V[1], V[2], V[3]);
	center[2] = center_z(V[0], V[1], V[3]);
	center[3] = center_z(V[0], V[2], V[3]);

	for (i = 0; i < 4; ++i) {
		k = i;
		for (j = i; j < 4; ++j)
			if (center[k] > center[j])
				k = j;
		if (i != k) {
			swp = center[i];
			center[i] = center[k];
			center[k] = swp;

			j = mas[i];
			mas[i] = mas[k];
			mas[k] = j;
		}
	}
	for (i = 0; i < 4; ++i) {
		switch (mas[i]) {
		case 0:
			paint_trinagle(bmp, V[0], V[1], V[2], COLORREF(COL_PYR::zero));
			break;
		case 1:
			paint_trinagle(bmp, V[1], V[2], V[3], COLORREF(COL_PYR::one));
			break;
		case 2:
			paint_trinagle(bmp, V[0], V[1], V[3], COLORREF(COL_PYR::two));
			break;
		case 3:
			paint_trinagle(bmp, V[0], V[2], V[3], COLORREF(COL_PYR::three));
			break;
		}
	}
}