#include <stdio.h>
#include <conio.h>
#include <windows.h>

enum CellType {
	Empty
};

class Field {
	HANDLE printConsole;
	
	int h, w;
	CellType field[30][30];
	
	void init_display() {
		CONSOLE_CURSOR_INFO cci;
		printConsole = GetStdHandle( STD_OUTPUT_HANDLE );
		GetConsoleCursorInfo( printConsole, &cci );
		cci.bVisible = FALSE;							//カーソルを非表示にする設定
		SetConsoleCursorInfo( printConsole, &cci );
	}
	
	void locate(int y, int x) {
		COORD dwPos;
		dwPos.X = x;
		dwPos.Y = y;
		SetConsoleCursorPosition( printConsole, dwPos );	//カーソルをy行x列目にセット
	}
	
public:
	void createField(int h, int w) {
		init_display();
		
		this->h = h;
		this->w = w;
		
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				field[y][x] = Empty;
			}
		}
	}
	
	void drawField() {
		locate(0, 0);
		
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				if (field[y][x] == Empty) {
					printf("空");
				}
			}
			printf("\n");
		}
	}
};

Field field;

int main() {
	field.createField(20, 20);
	
	system("cls");
	while(true) {
		field.drawField();
	}
	
	return 0;
}