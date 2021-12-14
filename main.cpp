#include <conio.h>
#include "pyr_4.h"
#include "pyr.h"
#include <iostream>
#include <string>

int main() {
	system("color 38");
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_WINDOWED_MODE, nullptr);
	MoveWindow(GetConsoleWindow(), 20, 20, 1260, 680,true);
	int c;
	char flag = '+';
	BitMap bmp_one(
		(int)(DIM_BMP_ONE::width), 
		(int)(DIM_BMP_ONE::height), 
		(int)(DIM_BMP_ONE::left_margin),
		(int)(DIM_BMP_ONE::top_margin),
		(COLORREF)(COL_BMP::clear)
	);
	BitMap bmp_two(
		(int)(DIM_BMP_TWO::width),
		(int)(DIM_BMP_TWO::height),
		(int)(DIM_BMP_TWO::left_margin),
		(int)(DIM_BMP_TWO::top_margin),
		(COLORREF)(COL_BMP::clear)
	);
	pyr_4 pyramid_4(&bmp_one); //Рисуем
	pyr pyramid(&bmp_two); //Рисуем
	figure *ptr = &pyramid_4;

	bmp_one.DrawBitmap();
	bmp_two.DrawBitmap();

	bool run = true;
	bool refresh = true;

	


	while (run) {

		c = 1;
		if (_kbhit()) {

			c = _getch();
		}
		
		switch (c) {
		case 113: {
			run = false;
			break;
		}
				
		case 77:
			ptr->move('x', '+');
			refresh = true;
			break;
		case 75:
			ptr->move('x', '-');
			refresh = true;
			break;
		case 80:
			ptr->move('y', '+');
			refresh = true;
			break;
		case 72:
			ptr->move('y', '-');
			refresh = true;
			break;
		case 91:
			ptr->move('z', '+');
			refresh = true;
			break;
		case 93:
			ptr->move('z', '-');
			refresh = true;
			break;
		// смена двигаемой фигуры
		case 49:
			ptr = &pyramid_4;
			break;
		case 50:
			ptr = &pyramid;
			break;
		case 32:
			(flag == '+') ? flag = '-' : flag = '+';
			break;
		case 120:
			ptr->rotate('x', flag);
			refresh = true;
			break;
		case 121:
			ptr->rotate('y', flag);
			refresh = true;
			break;
		case 122:
			ptr->rotate('z', flag);
			refresh = true;
			break;
		case 44:
			ptr->zoom('-');
			refresh = true;
			break;
		case 46:
			ptr->zoom('+');
			refresh = true;
			break;
		}

		
		if (refresh) {
			refresh = false;

			pyramid_4.refresh();
			pyramid.refresh();
			bmp_one.DrawBitmap();
			bmp_two.DrawBitmap();
		}

	}


	return 0;
}