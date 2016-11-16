#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

enum CellType {
	Empty, Bomb
};

class Player {
	int h, w;
	int y, x;
	
public:
	void createPlayer(int fieldHeight, int fieldWidth, int initY, int initX) {
		h = fieldHeight;
		w = fieldWidth;
		y = initY;
		x = initX;
	}
	
	void move() {
		if (!kbhit()) return;	//キーが押されてなければ何もしない
		
		char c = getch();
		
		//↑→↓← = wdsa
		if (c == 'w') { y = (y - 1 + h) % h; }
		if (c == 'd') { x = (x + 1) % w; }
		if (c == 's') { y = (y + 1) % h; }
		if (c == 'a') { x = (x - 1 + w) % w; }
	}
	
	bool isExist(int y, int x) {
		if (this->y == y && this->x == x) { return true; }
		return false;
	}
};

class Field {
	HANDLE printConsole;
	
	int h, w;
	CellType field[30][30];		//プレイヤーを除いたマップ (背景)
	Player player;				//プレイヤー
	
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
				int t = rand() % 100;
				if (t < 80) { field[y][x] = Empty; }
				else { field[y][x] = Bomb; }
			}
		}
		
		player.createPlayer(h, w, 0, 0);
	}
	
	void move() {
		player.move();
	}
	
	void drawField() {
		locate(0, 0);
		
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				if (player.isExist(y, x)) { printf("人"); continue; }
				if (field[y][x] == Empty) { printf("　"); }
				if (field[y][x] == Bomb)  { printf("爆"); }
			
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
		field.move();
		field.drawField();
	}
	
	return 0;
}