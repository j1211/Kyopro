//���d���ł��܂��B�O���̃��[�v��1����Ԃɓ����̃��[�v�����邮����C���[�W�ł��B

//����́A5�s10��̒����`���o�͂���R�[�h�ɂȂ�܂��B

#include <iostream>
using namespace std;

int main() {
	int h = 5, w = 10;
	int i, j;
	
	i = 0;
	while (i < h) {
		j = 0;
		while (j < w) {
			cout << "o";
			j++;
		}
		cout << endl;
		i++;
	}
	
	return 0;
}

//�R���\�[����ʁi������ʁj�ł́A���̏��Ԃŕ������o�͂����̂ŁA
//�O���̃��[�v���s�o��, �����̃��[�v���i�e�s�ɂ�����j��o�͂ɂȂ��Ă��܂��B

//�o�͏�
//0 1 2 3
//4 5 6 7
//8 9 �c
