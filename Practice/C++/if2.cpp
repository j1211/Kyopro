//����͐��є���ł��B80�ȏ��Great, 60�ȏ��Good, 50�ȏ��Ok, 49�ȉ���fail

#include <iostream>
using namespace std;

int main() {
	int score;

	cin >> score;
	
	if (score >= 80) {
		cout << "Great" << endl;
	}
	else if (score >= 60) {
		cout << "Good" << endl;
	}
	else if (score >= 50) {
		cout << "Ok" << endl;
	}
	else {
		cout << "fail" << endl;
	}
	cout << "����I��" << endl;
	return 0;
}

//if �c ����, else if �c ����ȊO�ł���, else �c ����ȊO
//if (A) { /*1*/ } else if (B) { /*2*/ } else { /*3*/ } /*4*/
//�Ƃ������ɏ����ꂽ�v���O���������s����Ɓc

//A����������Ȃ�1 -> 4�̏��Ŏ��s�����B
//A����������B����������Ȃ�2 -> 4�̏��Ŏ��s�����
//A��B���������Ȃ����3 -> 4�̏��Ŏ��s�����B

//�Ō��else�͏����Ȃ��Ă��悢���Aelse if��2�ȏ゠���Ă��悢
//�܂��Aif (A) { } else { } �Ƃ������������\