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
//if (A) { /*�@*/ } else if (B) { /*�A*/ } else { /*�B*/ } /*�C*/
//�Ƃ������ɏ����ꂽ�v���O���������s����Ɓc

//A����������Ȃ�@ -> �C�̏��Ŏ��s�����B
//A����������B����������Ȃ�A -> �C�̏��Ŏ��s�����
//A��B���������Ȃ���·B -> �C�̏��Ŏ��s�����B

//�Ō��else�͏����Ȃ��Ă��悢���Aelse if��2�ȏ゠���Ă��悢
//�܂��Aif (A) { } else { } �Ƃ������������\