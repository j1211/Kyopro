//while�̓r��( = {}�̒�) �Ń��[�v���甲�������ꍇ�́Abreak���g���܂��B

//����́A0����9�܂ł��o�͂���R�[�h�ł��B ���Ȃ݂�break���Ȃ��ƁA�������[�v�ɂȂ�܂��B

#include <iostream>
using namespace std;

int main() {
	int i;
	
	i = 0;
	while (true) {	//�������͏�ɐ^
		cout << i << endl;
		i++;
		if (i >= 10) {
			break;
		}
	}
	
	return 0;
}


//�]�k�F
//if, while�Ȃǂ̐��䕶�ɂ����āA{}�̒���1�s�����Ȃ�{}���ȗ����邱�Ƃ��ł��܂��B
//�Ⴆ�΁A15�`17�s�ڂ��F
//if (i >= 10) break;
//�Ə������Ƃ��ł���B
