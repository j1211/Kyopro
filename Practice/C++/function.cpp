//�֐��Ƃ́c��A�̏������܂Ƃ߂ċL�q�������́B�l��n������Ԃ�����ł���B�������肭�g����, �v���O�������ȒP�ɏ����܂��B(main�͒����I��, hoge()�Ƃ��͒P���ɏ�����j
//C++�̊֐��i�傫��������4�p�^�[���j
//                �����Fvoid hoge() { B;C;D; } int main() { A; hoge(); E; } �̂悤�ɏ�����, �v���O������ABCDE�̏��ŏ������܂��B
//        �߂�l�{�����Fint fuga() { B;C;D; return 10; } int main() { int a = fuga(); } �̂悤�ɏ�����, �v���O������B,C,D�����s������, a��10 (disp��return�����l)���������܂��B
//          �����{�����Fvoid disp(int a) { printf("%d\n", a); } int main() { disp(10); }�̂悤�ɏ�����, �v���O������10��\�����܂��B(disp��a��10������disp�������s�j
//  �����{�߂�l�{�����G�T���v���ŏ����܂��B

#include <iostream>
using namespace std;

int func(int n) {
	for (int i = 0; i < n * n; i++) { cout << "o"; }
	
int main() {
	return 0;
}
