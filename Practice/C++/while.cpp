//while (������) { /*�������^�̂Ƃ��̏���*/ }	//}�܂ŗ�����u�������v�܂Ŗ߂�
//�܂�A�����������藧�Ԃ�, while�̒������邮����܂��B

#include <iostream>
using namespace std;

int main() {
	int i = 0;
	
	while (i < 10) {
		cout << i << endl;	//i�̒l���o�͂���.
		i = i + 1;			//i�̒l��1���₷. i++;�Ə����Ă��悢�B
	}
	
	cout << "while���𔲂��܂����Bi = " << i << endl;
	
	return 0;
}
