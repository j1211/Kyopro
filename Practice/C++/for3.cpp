//for����break�Ŕ����邱�Ƃ��ł��܂��B
//break�Ŕ�������for����1�ł��邱�Ƃɒ��ӂ��Ă��������B

//���e��for2.cpp�Ɠ����ŁA�c5 * ��10�̒����`�̕\���A�ƂȂ��Ă���܂�

#include <iostream>
using namespace std;

int main() {
	int h = 5, w = 10;
	int i, j;
	
	for (i = 0; i < h; i++) {
		for (j = 0; ; j++) {
			if (j >= w) {
				break;
			}
			cout << "o";
		}
		cout << endl;
	}
	
	return 0;
}