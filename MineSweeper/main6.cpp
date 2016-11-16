//今までのあらすじ：マップを表示した -> キャラクターの移動をした -> ゲームオーバー/クリアを実装した
//移動回数をつけてみよう
//マップを（自身と周囲8マスの爆弾の数に）変換して, 表示しよう。ただし, マップ外のマスは見ないようにする。 -> 大文字で数字を表示しよう

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

enum CellType {
	Empty, Bomb, Goal
};

class Player {
	int h, w;
	int y, x;
	int move_cnt;
	
public:
	void createPlayer(int fieldHeight, int fieldWidth, int initY, int initX) {
		h = fieldHeight;
		w = fieldWidth;
		y = initY;
		x = initX;
		move_cnt = 0;
	}
	
	void move() {
		if (!kbhit()) return;	//キーが押されてなければ何もしない
		
		char c = getch();
		
		//↑→↓← = wdsa
		if (c == 'w') { y = (y - 1 + h) % h; move_cnt++; }
		if (c == 'd') { x = (x + 1) % w;     move_cnt++; }
		if (c == 's') { y = (y + 1) % h;     move_cnt++; }
		if (c == 'a') { x = (x - 1 + w) % w; move_cnt++; }
	}
	
	bool isExist(int y, int x) {
		if (this->y == y && this->x == x) { return true; }
		return false;
	}
	
	int getMoveCount() { return move_cnt; }
};

class Field {
	HANDLE printConsole;
	
	int h, w;
	CellType field[30][30];		//プレイヤーを除いたマップ (背景)
	Player player;				//プレイヤー
	int goal_y, goal_x;			//ゴールの場所
	
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
	
	void createBombNums( int bombNums[] ) {
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				int cnt = 0;
				
				for (int dy = -1; dy <= 1; dy++) {
					for (int dx = -1; dx <= 1; dx++) {
						if (y + dy < 0 || y + dy >= h || x + dx < 0 || x + dx >= w) { continue; }	//範囲外マスは無視
						if (field[y + dy][x + dx] == Bomb) { cnt++; }
					}
				}
				bombNums[y * w + x] = cnt;		//y行x列目の爆弾の数は, [y * w + x]番目に入れる
			}
		}
	}
	
	//0->"０"みたいな変換をする。
	//0 <= val <= 9と仮定し, valを大文字に変換する。(一応エラー処理も入れるけど！）
	string toOmoji( int val ) {
		string ret[11] = {"０", "１", "２", "３", "４", "５", "６", "７", "８", "９", "Ｎ"};
		return ret[val];
	}
	
public:
	void createField(int h, int w) {
		init_display();
		
		this->h = h;
		this->w = w;
		
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				int t = rand() % 100;
				if ((y == 0 && x == 0) || t < 80) { field[y][x] = Empty; }	//プレイヤーのいるマスと, その他80％のマスを「何もないマス」にする
				else { field[y][x] = Bomb; }
			}
		}
		goal_y = h - 1;
		goal_x = w - 1;
		field[goal_y][goal_x] = Goal;		//右下をゴールにする
		
		player.createPlayer(h, w, 0, 0);
	}
	
	void move() {
		player.move();
	}
	
	void drawField() {
		locate(0, 0);
		
		int bombNums[30 * 30];
		createBombNums( bombNums );
		
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				if (player.isExist(y, x)) { printf("人"); continue; }
				if (field[y][x] == Goal)  { printf("Ｇ"); continue; }
				printf("%s", toOmoji( bombNums[y * w + x] ).c_str());
			}
			printf("\n");
		}
		printf("\n移動回数 = %d\n", player.getMoveCount());
	}
	
	//人がいるところに爆弾があったらゲームオーバー(O(1)) ⇔ 爆弾があるところに人がいたらゲームオーバー(O(HW))
	bool isGameOver() {
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				if (field[y][x] == Bomb && player.isExist(y, x)) {
					return true;
				}
			}
		}
		return false;
	}
	
	//ゴールがあるところに人がいたらゲームクリア
	bool isGameClear() {
		if (player.isExist(goal_y, goal_x)) { return true; }
		return false;
	}
};

Field field;

int main() {
	field.createField(10, 10);
	
	system("cls");
	while(true) {
		field.move();
		field.drawField();
		
		if (field.isGameOver()) {
			printf("\n爆弾にあたって死んだ\n");
			break;
		}
		if (field.isGameClear()) {
			printf("\nゲームクリア！\n");
			printf("…ところで, ！を付けてテンション上げた気になってる開発者なんていないよね\n");
			break;
		}
	}
	
	return 0;
}