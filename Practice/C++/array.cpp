//�z��c�����f�[�^�^�̕ϐ�����ׂ�����
//�Ⴆ�΁Aint a[5]; �̂悤�ɐ錾����ƁA���������锠 �ua[0], a[1], a[2], a[3], a[4], a[5]�v���ł���B
//���Ƃ́A���ʂ̕ϐ��̂悤�Ɏg���΂悢�B

//�Ȃ��A�S���̗v�f��0�ŏ������������Ȃ�Aint a[5] = {0}; �̂悤�ɏ����΂悢�B
//�������Aint a[5] = {1};�̂悤�ɏ����ƁAa[0] = 1�ɂȂ邪a[1]�`a[4]��1�ɂȂ�Ȃ��̂Œ��ӁB

//���ӓ_: int a[n]; �̂悤�ɂ͐錾�ł��Ȃ��B

//�]�k�F�������̃A�h���X�i�ϐ��̏ꏊ�j�͘A�ԂɂȂ�B

//���̃v���O�����́A���͂��ꂽ5�̐���(���s, �܂���, �󔒂ŋ�؂��ē���)���t���ŕ\������v���O�����ł��B

#include <iostream>
using namespace std;

int a[5];

int main() {
	int i;
	
	for (i = 0; i < 5; i++) {	//cin >> a[0] >> a[1] >> �c >> a[4]; �Ə����̂��ʓ|�������̂�for�����g��.
		cin >> a[i];
	}
	
	for (i = 4; i >= 0; i--) {
		cout << a[i] << endl;
	}
	
	return 0;
}