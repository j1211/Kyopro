//����ʂ��̂͐���ʁi�}�E�X����̐���Ȃ������j
#include "DxLib.h"
#include <vector>
using namespace std;

const int WINDOW_X = 900;
const int WINDOW_Y = 700;

enum KOMA {
	EMPTY, M_FU, M_HISYA, M_KAKU, M_KYOSYA, M_KEIMA, M_GIN, M_KIN, M_OU,
	E_FU, E_HISYA, E_KAKU, E_KYOSYA, E_KEIMA, E_GIN, E_KIN, E_OU
};

KOMA board[9][9];			//{���w7,8,9�s��}, {�G�w0,1,2�s��} (���オ0�s0���)
vector<KOMA> motigoma[2];	//motigoma[0]�c�����̎�����, motigoma[1]�c�G�̎�����
int handle_koma_y, handle_koma_x;	//����ł����(�s, ��)�i�Ȃ����(-1, -1), ������Ȃ�(id, -1)�j

namespace Board {
	const int lx = 200;
	const int ly = 100;
	const int cellsize = 25;

	int row(int y) { if (y < ly) return -1; return (y - ly) / cellsize; }
	int col(int x) { if (x < lx) return -1; return (x - lx) / cellsize; }
};

namespace Motigoma {
	const int lx[2] = {25, 600};
	const int ly[2] = {500, 100};
	const int width		= 150;
	const int height	= 200;
	const int cellsize	= 25;

	int id(int player, int y, int x) {
		if (y < ly[player]) return -1;
		if (x < lx[player]) return -1;

		int numY = height / cellsize;
		int numX = width / cellsize;

		if (y > ly[player] + numY * cellsize) return -1;
		if (x > lx[player] + numX * cellsize) return -1;

		int row = (y - ly[player]) / cellsize;
		int col = (x - lx[player]) / cellsize;

		if (row * numX + col >= motigoma[player].size()) return -1;
		return row * numX + col;
	}
};

class Mouse {
	int x, y;
	int prev_state, state;
public:
	Mouse() {
		x = 0; y = 0; state = 0;
	}
	void update() {
		GetMousePoint(&x, &y);
		prev_state = state;
		state = GetMouseInput();
	}
	bool click_left() {
		return (!(prev_state & MOUSE_INPUT_LEFT)) && (state & MOUSE_INPUT_LEFT);
	}
	bool push_left() {
		return (state & MOUSE_INPUT_LEFT);
	}
	int getX() { return x; }
	int getY() { return y; }
};
Mouse mouse;


void endGame() {
	DxLib_End(); // DX���C�u�����I������
    exit(0);
}

void init_game() {
	int r, c;
	for (r = 0; r < 9; r++) for (c = 0; c < 9; c++) board[r][c] = EMPTY;
	motigoma[0].clear();
	motigoma[1].clear();

	board[0][0] = E_KYOSYA;
	board[0][1] = E_KEIMA;
	board[0][2] = E_GIN;
	board[0][3] = E_KIN;
	board[0][4] = E_OU;
	for (c = 5; c < 9; c++) board[0][c] = board[0][8 - c];
	board[1][1] = E_HISYA;
	board[1][7] = E_KAKU;
	for (c = 0; c < 9; c++) board[2][c] = E_FU;

	board[8][0] = M_KYOSYA;
	board[8][1] = M_KEIMA;
	board[8][2] = M_GIN;
	board[8][3] = M_KIN;
	board[8][4] = M_OU;
	for (c = 5; c < 9; c++) board[8][c] = board[8][8 - c];
	board[7][1] = M_KAKU;
	board[7][7] = M_HISYA;
	for (c = 0; c < 9; c++) board[6][c] = M_FU;

	handle_koma_y = -1;
	handle_koma_x = -1;
}

int is_end() {
	//0�cfalse, 1�cmy won, -1�cenemy won
	bool m_ou = false;
	bool e_ou = false;

	for (int r = 0; r < 9; r++) {
		for (int c = 0; c < 9; c++) {
			if (board[r][c] == M_OU) m_ou = true;
			if (board[r][c] == E_OU) e_ou = true;
		}
	}
	if (m_ou && e_ou) return 0;
	if (m_ou) return 1;
	return -1;
}

void drawKoma(int ly, int lx, KOMA koma) {
	switch (koma) {
	case M_FU:		DrawFormatString(lx, ly, 0, "��"); break;
	case M_HISYA:	DrawFormatString(lx, ly, 0, "��"); break;
	case M_KAKU:	DrawFormatString(lx, ly, 0, "�p"); break;
	case M_KYOSYA:	DrawFormatString(lx, ly, 0, "��"); break;
	case M_KEIMA:	DrawFormatString(lx, ly, 0, "�j"); break;
	case M_GIN:		DrawFormatString(lx, ly, 0, "��"); break;
	case M_KIN:		DrawFormatString(lx, ly, 0, "��"); break;
	case M_OU:		DrawFormatString(lx, ly, 0, "��"); break;
	case E_FU:		DrawFormatString(lx, ly, GetColor(255, 0, 0), "��"); break;
	case E_HISYA:	DrawFormatString(lx, ly, GetColor(255, 0, 0), "��"); break;
	case E_KAKU:	DrawFormatString(lx, ly, GetColor(255, 0, 0), "�p"); break;
	case E_KYOSYA:	DrawFormatString(lx, ly, GetColor(255, 0, 0), "��"); break;
	case E_KEIMA:	DrawFormatString(lx, ly, GetColor(255, 0, 0), "�j"); break;
	case E_GIN:		DrawFormatString(lx, ly, GetColor(255, 0, 0), "��"); break;
	case E_KIN:		DrawFormatString(lx, ly, GetColor(255, 0, 0), "��"); break;
	case E_OU:		DrawFormatString(lx, ly, GetColor(255, 0, 0), "��"); break;				
	}
}

void drawBoard() {
	int r, c;

	//��
	for (r = 0; r < 9; r++) {
		int ly = r * Board::cellsize + Board::ly;
		for (c = 0; c < 9; c++) {
			int lx = c * Board::cellsize + Board::lx;
			DrawBox(lx, ly, lx + Board::cellsize + 1, ly + Board::cellsize + 1, 0, FALSE);
		}
	}

	//��
	for (r = 0; r < 9; r++) {
		int ly = r * Board::cellsize + Board::ly;
		for (c = 0; c < 9; c++) {
			if (r == handle_koma_y && c == handle_koma_x) {	//����ł����͕`�悵�Ȃ�
				continue;
			}
			int lx = c * Board::cellsize + Board::lx;
			drawKoma(ly, lx, board[r][c]);
		}
	}
}

void drawMotigoma() {
	//���
	DrawBox(Motigoma::lx[0], Motigoma::ly[0], Motigoma::lx[0] + Motigoma::width, Motigoma::ly[0] + Motigoma::height, 0, FALSE);
	DrawBox(Motigoma::lx[1], Motigoma::ly[1], Motigoma::lx[1] + Motigoma::width, Motigoma::ly[1] + Motigoma::height, 0, FALSE);

	//��
	for (int i = 0; i < 2; i++) {
		int numX = Motigoma::width / Motigoma::cellsize;

		for (int j = 0; j < motigoma[i].size(); j++) {
			if (handle_koma_x == -1 && handle_koma_y == j) {	//����ł����͕`�悵�Ȃ�
				continue;
			}
			int ly = (j / numX) * Motigoma::cellsize + Motigoma::ly[i];
			int lx = (j % numX) * Motigoma::cellsize + Motigoma::lx[i];
			drawKoma(ly, lx, motigoma[i][j]);
		}
	}
}

void drawHandlekoma(int player) {
	//����ł����
	if (handle_koma_y == -1) return;
	if (handle_koma_x != -1) drawKoma(mouse.getY(), mouse.getX(), board[handle_koma_y][handle_koma_x]);
	else drawKoma(mouse.getY(), mouse.getX(), motigoma[player][handle_koma_y]);
}

void drawInfo() {
}

bool is_range(int r, int c) {
	return (0 <= r && r < 9 && 0 <= c && c < 9);
}

bool is_exist(int turn, int r, int c) {
	if (board[r][c] == EMPTY) return false;
	if (board[r][c] <= M_OU) return (turn == 0);
	return (turn == 1);
}

bool canMove(int player, int r, int c, int nr, int nc) {
	if (!is_range(r, c) || !is_range(nr, nc) || (r == nr && c == nc)) return false;
	if (!is_exist(player, r, c)) return false;

	int lx = min(c, nc);
	int rx = max(c, nc);
	int ly = min(r, nr);
	int ry = max(r, nr);

	switch (board[r][c]) {
	case M_FU:
		return !is_exist(0, nr, nc) && (c == nc) && (r - nr == 1);
	case M_HISYA:
		if (r == nr) {
			for (int i = lx + 1; i < rx; i++) {
				if (board[r][i] != EMPTY) {
					return false;
				}
			}
			return !is_exist(0, nr, nc);
		}
		else if (c == nc) {
			for (int i = ly + 1; i < ry; i++) {
				if (board[i][c] != EMPTY) {
					return false;
				}
			}
			return !is_exist(0, nr, nc);
		}
		return false;
	case M_KAKU:
		if (rx - lx != ry - ly) return false;
		for (int i = 1; i < rx - lx; i++) {
			int y = r + ((nr > r) ? i : -i);
			int x = c + ((nc > c) ? i : -i);
			if (board[y][x] != EMPTY) {
				return false;
			}
		}
		return !is_exist(0, nr, nc);
	case M_KYOSYA:
		if (c != nc || r <= nr) return false;
		for (int i = r - 1; i > nr; i--) {
			if (board[i][c] != EMPTY) {
				return false;
			}
		}
		return !is_exist(0, nr, nc);
	case M_KEIMA:
		if (r - nr != 2 || abs(nc - c) != 1) return false;
		return !is_exist(0, nr, nc);
	case M_GIN:
		if (max(rx - lx, ry - ly) != 1) return false;
		if (rx - lx + ry - ly == 1 && nr != r - 1) return false;
		return !is_exist(0, nr, nc);
	case M_KIN:
		if (max(rx - lx, ry - ly) != 1) return false;
		if (nr == r + 1 && rx - lx == 1) return false;
		return !is_exist(0, nr, nc);
	case M_OU:
		if (max(rx - lx, ry - ly) != 1) return false;
		return !is_exist(0, nr, nc);
	case E_FU:
		return !is_exist(1, nr, nc) && (c == nc) && (nr - r == 1);
	case E_HISYA:
		if (r == nr) {
			for (int i = lx + 1; i < rx; i++) {
				if (board[r][i] != EMPTY) {
					return false;
				}
			}
			return !is_exist(1, nr, nc);
		}
		else if (c == nc) {
			for (int i = ly + 1; i < ry; i++) {
				if (board[i][c] != EMPTY) {
					return false;
				}
			}
			return !is_exist(1, nr, nc);
		}
		return false;
	case E_KAKU:
		if (rx - lx != ry - ly) return false;
		for (int i = 1; i < rx - lx; i++) {
			int y = r + ((nr > r) ? i : -i);
			int x = c + ((nc > c) ? i : -i);
			if (board[y][x] != EMPTY) {
				return false;
			}
		}
		return !is_exist(1, nr, nc);
	case E_KYOSYA:
		if (c != nc || r >= nr) return false;
		for (int i = r + 1; i < nr; i++) {
			if (board[i][c] != EMPTY) {
				return false;
			}
		}
		return !is_exist(1, nr, nc);
	case E_KEIMA:
		if (nr - r != 2 || abs(nc - c) != 1) return false;
		return !is_exist(1, nr, nc);
	case E_GIN:
		if (max(rx - lx, ry - ly) != 1) return false;
		if (rx - lx + ry - ly == 1 && nr != r + 1) return false;
		return !is_exist(1, nr, nc);
	case E_KIN:
		if (max(rx - lx, ry - ly) != 1) return false;
		if (nr == r - 1 && rx - lx == 1) return false;
		return !is_exist(1, nr, nc);
	case E_OU:
		if (max(rx - lx, ry - ly) != 1) return false;
		return !is_exist(1, nr, nc);
	}
	return false;
}

//������
//(���[���G�����Ƃ���ɂ͒u���Ȃ��B�����Ȃ����ɂ͒u���Ȃ��B2���̓_����΁j
bool canPut(KOMA koma, int r, int c) {
	if (!is_range(r, c)) return false;
	if (board[r][c] != EMPTY) return false;
	return true;
}

void drawCanMovePosition(int player, int r, int c, int color) {
	for (int nr = 0; nr < 9; nr++) {
		for (int nc = 0; nc < 9; nc++) {
			if (!canMove(player, r, c, nr, nc)) continue;
			int ly = Board::ly + nr * Board::cellsize;
			int lx = Board::lx + nc * Board::cellsize;
			DrawBox(lx + 1, ly + 1, lx + Board::cellsize, ly + Board::cellsize, color, TRUE);
		}
	}
}

void drawCanPutPosition(KOMA koma, int color) {
	for (int r = 0; r < 9; r++) {
		for (int c = 0; c < 9; c++) {
			if (!canPut(koma, r, c)) continue;
			int ly = Board::ly + r * Board::cellsize;
			int lx = Board::lx + c * Board::cellsize;
			DrawBox(lx + 1, ly + 1, lx + Board::cellsize, ly + Board::cellsize, color, TRUE);
		}
	}
}

KOMA get_motigoma(KOMA taked_koma) {
	switch (taked_koma) {
	case M_FU:		return E_FU;
	case M_HISYA:	return E_HISYA;
	case M_KAKU:	return E_KAKU;
	case M_KYOSYA:	return E_KYOSYA;
	case M_KEIMA:	return E_KEIMA;
	case M_GIN:		return E_GIN;
	case M_KIN:		return E_KIN;
	case M_OU:		return E_OU;
	case E_FU:		return M_FU;
	case E_HISYA:	return M_HISYA;
	case E_KAKU:	return M_KAKU;
	case E_KYOSYA:	return M_KYOSYA;
	case E_KEIMA:	return M_KEIMA;
	case E_GIN:		return M_GIN;
	case E_KIN:		return M_KIN;
	case E_OU:		return M_OU;
	}
	return EMPTY;
}

void moveKoma(int player, int r, int c, int nr, int nc) {
	//�O������F��������
	if (board[nr][nc] != EMPTY) {
		motigoma[player].push_back(get_motigoma(board[nr][nc]));
	}
	board[nr][nc] = board[r][c];
	board[r][c] = EMPTY;
}

void action(int player) {
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		mouse.update();

		//����ł������X�V
		if (mouse.click_left()) {
			if (handle_koma_y == -1) {
				//���g�̋�i�Ֆ� or ������) ���N���b�N������, ���������.
				int row = Board::row(mouse.getY());
				int col = Board::col(mouse.getX());
				
				if (is_range(row, col) && is_exist(player, row, col)) {	//�Ֆʂ̃R�}������
					handle_koma_y = row;
					handle_koma_x = col;
				}
				int id = Motigoma::id(player, mouse.getY(), mouse.getX());
				if (id >= 0) {
					handle_koma_y = id;
					handle_koma_x = -1;
				}
			}
			else if (handle_koma_x == -1) {
				//�������u������u��. �u������, �֐��𔲂���. �u����u���Ȃ��Ɋւ�炸, ����ł��Ȃ���Ԃɂ���B
				int row = Board::row(mouse.getY());
				int col = Board::col(mouse.getX());
				bool flag = false;
				
				if (canPut(motigoma[player][handle_koma_y], row, col)) {	//���u��
					board[row][col] = motigoma[player][handle_koma_y];
					motigoma[player].erase(motigoma[player].begin() + handle_koma_y);	//��������폜
					flag = true;
				}
				handle_koma_y = -1;
				handle_koma_x = -1;
				if (flag) return;
			}
			else {
				//��𓮂���. ����������, �֐��𔲂���. �������铮�����Ȃ��Ɋւ�炸, ����ł��Ȃ���Ԃɂ���B
				int row = Board::row(mouse.getY());
				int col = Board::col(mouse.getX());
				bool flag = false;

				if (canMove(player, handle_koma_y, handle_koma_x, row, col)) {	//��𓮂���
					moveKoma(player, handle_koma_y, handle_koma_x, row, col);
					flag = true;
				}
				handle_koma_y = -1;
				handle_koma_x = -1;
				if (flag) return;
			}
		}

		drawBoard();			//�Ֆ�
		drawMotigoma();			//������
		//����ł���������͈͂�\��
		if (handle_koma_y != -1 && handle_koma_x != -1) {
			drawCanMovePosition(player, handle_koma_y, handle_koma_x, GetColor(255, 255, 0));
		}
		else if (handle_koma_y != -1) {
			drawCanPutPosition(motigoma[player][handle_koma_y], GetColor(255, 255, 0));
		}
		drawHandlekoma(player);	//����ł����̕\���i����łȂ��Ȃ�\�����Ȃ��j
	}
	if (ProcessMessage() != 0) { endGame(); }
}

void show_result(int state) {
}

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int)
{
        ChangeWindowMode(TRUE);	
		SetGraphMode(WINDOW_X, WINDOW_Y, 32);
		SetBackgroundColor(255, 255, 255);
		DxLib_Init();
		SetDrawScreen( DX_SCREEN_BACK );

		int player = 0, state;

		init_game();
		while (true) {
			action(player);
			state = is_end();
			if (state != 0) { break; }
			player = (player + 1) % 2;
		}
		show_result(state);

        DxLib_End(); // DX���C�u�����I������
        return 0;
}  
