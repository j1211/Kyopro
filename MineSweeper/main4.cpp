#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

enum CellType {
	Empty, Bomb, Goal
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
		if (!kbhit()) return;	//�L�[��������ĂȂ���Ή������Ȃ�
		
		char c = getch();
		
		//�������� = wdsa
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
	CellType field[30][30];		//�v���C���[���������}�b�v (�w�i)
	Player player;				//�v���C���[
	int goal_y, goal_x;			//�S�[���̏ꏊ
	
	void init_display() {
		CONSOLE_CURSOR_INFO cci;
		printConsole = GetStdHandle( STD_OUTPUT_HANDLE );
		GetConsoleCursorInfo( printConsole, &cci );
		cci.bVisible = FALSE;							//�J�[�\�����\���ɂ���ݒ�
		SetConsoleCursorInfo( printConsole, &cci );
	}
	
	void locate(int y, int x) {
		COORD dwPos;
		dwPos.X = x;
		dwPos.Y = y;
		SetConsoleCursorPosition( printConsole, dwPos );	//�J�[�\����y�sx��ڂɃZ�b�g
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
		goal_y = h - 1;
		goal_x = w - 1;
		field[goal_y][goal_x] = Goal;		//�E�����S�[���ɂ���
		
		player.createPlayer(h, w, 0, 0);
	}
	
	void move() {
		player.move();
	}
	
	void drawField() {
		locate(0, 0);
		
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				if (player.isExist(y, x)) { printf("�l"); continue; }
				if (field[y][x] == Empty) { printf("�@"); }
				if (field[y][x] == Bomb)  { printf("��"); }
				if (field[y][x] == Goal)  { printf("�f"); }
			}
			printf("\n");
		}
	}
	
	//�l������Ƃ���ɔ��e����������Q�[���I�[�o�[(O(1)) �� ���e������Ƃ���ɐl��������Q�[���I�[�o�[(O(HW))
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
	
	//�S�[��������Ƃ���ɐl��������Q�[���N���A
	bool isGameClear() {
		if (player.isExist(goal_y, goal_x)) { return true; }
		return false;
	}
};

Field field;

int main() {
	field.createField(20, 20);
	
	system("cls");
	while(true) {
		field.move();
		field.drawField();
		
		if (field.isGameOver()) {
			printf("\n���e�ɂ������Ď���\n");
			break;
		}
		if (field.isGameClear()) {
			printf("\n�Q�[���N���A�I\n");
			printf("�c�Ƃ����, �I��t���ăe���V�����グ���C�ɂȂ��Ă�J���҂Ȃ�Ă��Ȃ����\n");
			break;
		}
	}
	
	return 0;
}