//���܂ł̂��炷���F�}�b�v��\������ -> �L�����N�^�[�̈ړ������� -> �Q�[���I�[�o�[/�N���A����������
//�ړ��񐔂����Ă݂悤
//�}�b�v���i���g�Ǝ���8�}�X�̔��e�̐��Ɂj�ϊ�����, �\�����悤�B������, �}�b�v�O�̃}�X�͌��Ȃ��悤�ɂ���B -> �啶���Ő�����\�����悤

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
		if (!kbhit()) return;	//�L�[��������ĂȂ���Ή������Ȃ�
		
		char c = getch();
		
		//�������� = wdsa
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
	
	void createBombNums( int bombNums[] ) {
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				int cnt = 0;
				
				for (int dy = -1; dy <= 1; dy++) {
					for (int dx = -1; dx <= 1; dx++) {
						if (y + dy < 0 || y + dy >= h || x + dx < 0 || x + dx >= w) { continue; }	//�͈͊O�}�X�͖���
						if (field[y + dy][x + dx] == Bomb) { cnt++; }
					}
				}
				bombNums[y * w + x] = cnt;		//y�sx��ڂ̔��e�̐���, [y * w + x]�Ԗڂɓ����
			}
		}
	}
	
	//0->"�O"�݂����ȕϊ�������B
	//0 <= val <= 9�Ɖ��肵, val��啶���ɕϊ�����B(�ꉞ�G���[����������邯�ǁI�j
	string toOmoji( int val ) {
		string ret[11] = {"�O", "�P", "�Q", "�R", "�S", "�T", "�U", "�V", "�W", "�X", "�m"};
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
				if ((y == 0 && x == 0) || t < 80) { field[y][x] = Empty; }	//�v���C���[�̂���}�X��, ���̑�80���̃}�X���u�����Ȃ��}�X�v�ɂ���
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
		
		int bombNums[30 * 30];
		createBombNums( bombNums );
		
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				if (player.isExist(y, x)) { printf("�l"); continue; }
				if (field[y][x] == Goal)  { printf("�f"); continue; }
				printf("%s", toOmoji( bombNums[y * w + x] ).c_str());
			}
			printf("\n");
		}
		printf("\n�ړ��� = %d\n", player.getMoveCount());
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
	field.createField(10, 10);
	
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