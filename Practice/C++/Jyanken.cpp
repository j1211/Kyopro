/*hello.cpp, hensu.cpp�͓ǂ�ł����������悢�����c*/
//����񂯂�Q�[���ł��B�O�[(0), �`���L(1), �p�[(2)��2�l���o���đΐ킵�܂��B
//�Ȃ��Aif���͑��d��(=�l�X�g)�ł��܂��B�Ƃ�����{}���g���\���͑��d���ł���B

//�����ƌ��������܂����A�����Ē��������Ă��܂��B

#include <iostream>
using namespace std;

int main() {
	int a, b;

	cout << "����񂯂�Q�[��" << endl;	//;�����߂̋�؂�(1�s). endl�͉��s.
	cout << "A����̎�(0�`2) > "; cin >> a;
	cout << "B����̎�(0�`2) > "; cin >> b;

	if (a == 0) {
		if (b == 0) {
			cout << "�O�[�ƃO�[�ł������I" << endl;
		}
		else if (b == 1) {
			cout << "�O�[�ƃ`���L��A�̏���" << endl;
		}
		else {
			cout << "�O�[�ƃp�[��B�̏���" << endl;
		}
	}

	else if (a == 1) {
		if (b == 0) {
			cout << "�`���L�ƃO�[��B�̏���" << endl;
		}
		else if (b == 1) {
			cout << "�`���L�ƃ`���L�ł�����!" << endl;
		}
		else {
			cout << "�`���L�ƃp�[��A�̏���" << endl;
		}
	}

	else {
		if (b == 0) {
			cout << "�p�[�ƃO�[��A�̏���" << endl;
		}
		else if (b == 1) {
			cout << "�p�[�ƃ`���L��B�̏���" << endl;
		}
		else {
			cout << "�p�[�ƃp�[�ł�����!" << endl;
		}
	}
	
	return 0;
}