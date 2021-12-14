#include "pyr_4.h"


pyr_4::pyr_4(BitMap *bmp) : figure(bmp, (size_t)(NUM_VER::pyr_2)) {

	Ver[0] = { 130.0, 130.0, 130.0, 1.0 };
	Ver[1] = { 230.0, 130.0, 130.0, 1.0 };
	Ver[2] = { 230.0, 230.0, 130.0, 1.0 };
	Ver[3] = { 180.0, 180.0, 200.0, 1.0 };
	Ver[4] = { 130.0, 230.0, 130.0, 1.0 };
	Ver[5] = { 180.0, 180.0, 130.0, 1.0 };

	SetPR();
	SetShadow(COLORREF(COL_BMP::shadow));
	SetCenter();
	SetBitMap();

}
void pyr_4::ClrBitMap() {

	paint_trinagle(bmp, V[1], V[2], V[3], COLORREF(COL_BMP::clear));
	paint_trinagle(bmp, V[0], V[1], V[3], COLORREF(COL_BMP::clear));
	paint_trinagle(bmp, V[4], V[2], V[3], COLORREF(COL_BMP::clear));
	paint_trinagle(bmp, V[0], V[3], V[4], COLORREF(COL_BMP::clear));
	paint_trinagle(bmp, V[0], V[1], V[5], COLORREF(COL_BMP::clear));
	paint_trinagle(bmp, V[1], V[2], V[5], COLORREF(COL_BMP::clear));
	paint_trinagle(bmp, V[2], V[4], V[5], COLORREF(COL_BMP::clear));
	paint_trinagle(bmp, V[4], V[0], V[5], COLORREF(COL_BMP::clear));


	SetShadow(COLORREF(COL_BMP::clear));
}
void pyr_4::SetShadow(COLORREF c) {

	size_t i;

	vector<double> tmp;

	for (i = 0; i < numVer; ++i) {

		tmp.push_back(Ver[i][1]);

		Ver[i][1] = offset;

	}

	SetPR();

	paint_trinagle(bmp, V[1], V[2], V[3], c);
	paint_trinagle(bmp, V[0], V[1], V[3], c);
	paint_trinagle(bmp, V[4], V[2], V[3], c);
	paint_trinagle(bmp, V[0], V[3], V[4], c);
	paint_trinagle(bmp, V[0], V[1], V[5], c);
	paint_trinagle(bmp, V[1], V[2], V[5], c);
	paint_trinagle(bmp, V[2], V[4], V[5], c);
	paint_trinagle(bmp, V[4], V[0], V[5], c);

	for (i = 0; i < numVer; ++i) {

		Ver[i][1] = tmp[i];

	}

	SetPR();

}
void pyr_4::SetBitMap() {

	size_t i, j, k;
	int mas[9] = { 0, 1, 2, 3, 4, 5, 6, 7};
	double swp;

	double center[8];


	center[0] = center_z(V[0], V[1], V[5]);
	center[1] = center_z(V[1], V[2], V[5]);
	center[2] = center_z(V[2], V[4], V[5]);
	center[3] = center_z(V[4], V[0], V[5]);

	center[4] = center_z(V[1], V[2], V[3]);
	center[5] = center_z(V[0], V[1], V[3]);
	center[6] = center_z(V[0], V[3], V[4]);
	center[7] = center_z(V[2], V[3], V[4]);

	for (i = 0; i < 8; ++i) {
		k = i;
		for (j = i; j < 8; ++j)
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
	for (i = 0; i < 8; ++i) {

		switch (mas[i]) {

		case 0:
			paint_trinagle(bmp, V[0], V[1], V[5], COLORREF(COL_PYR::zero));
			break;

		case 1:
			paint_trinagle(bmp, V[1], V[2], V[5], COLORREF(COL_PYR::zero));
			break;

		case 2:
			paint_trinagle(bmp, V[2], V[4], V[5], COLORREF(COL_PYR::zero));
			break;

		case 3:
			paint_trinagle(bmp, V[4], V[0], V[5], COLORREF(COL_PYR::zero));
			break;

		case 4:
			paint_trinagle(bmp, V[1], V[2], V[3], COLORREF(COL_PYR::one));
			break;
		case 5:
			paint_trinagle(bmp, V[0], V[1], V[3], COLORREF(COL_PYR::two));
			break;
		case 6:
			paint_trinagle(bmp, V[0], V[3], V[4], COLORREF(COL_PYR::three));
			break;
		case 7:
			paint_trinagle(bmp, V[2], V[3], V[4], COLORREF(COL_PYR::four));
			break;
		}

	}
}
