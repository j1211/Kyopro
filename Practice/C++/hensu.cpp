//����̓R�����g�ł�
/*
	������R�����g�ł�
*/

//�ϐ� = �l�����锠
//�^ = �ϐ��ɓ����l�̎�� (���^�̎�ށj
//int�c-2^31 �` 2^31 - 1�̐���, 32bit
//double�c�����i���m�ɂ�, ���������_���j, 64bit
//char�c���p����(abcABC012_�Ȃ�), 8bit
//long long�c-2^63�`-2^63 - 1�̐���, 64bit
//bool�ctrue(�^), false(�U), 8bit

//�Ⴆ�΁Achar a; �Ƃ���ƁA���p���������邽�߂̔�(���O��a)���ł���B


#include <iostream>	//���܂��Ȃ�
using namespace std;	//std::cout��cout�Ə������߂̂��܂��Ȃ�

int main() {		//�v���O�����͂�������n�܂�(�ォ�牺�֎��s, ;�i�Z�~�R�����j�����̋�؂�j
	int a;
	a = 10;
	a = a + 2;	//�E����]���B=�͑�����Z�q�Ba <- 10 + 2�ƂȂ�̂ŁAa��12�ɏ��������B
	cout << "a = " << a << endl;
	return 0;
}
