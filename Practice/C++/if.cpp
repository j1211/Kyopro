//if (����) { /*1*/ } /*2*/
//���� == �^�̂Ƃ��i���������藧�Ƃ��j 1 -> 2�̏��Ŏ��s�����iif��{}���ɓ���j
//���� == �U�̂Ƃ��i���������藧���Ȃ��Ƃ��j�A2�̏��Ŏ��s�����iif��{}���ɓ���Ȃ��j

#include <iostream>
using namespace std;

int main() {
	int a, b;

	cin >> a >> b;

	if (a > b) {
		cout << "a��b�Ɠ������ł�" << endl;
	}
	cout << "a = " << a << " b = " << b << endl;

	return 0;
}