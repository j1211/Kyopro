//10^8�ȉ��̐���n���^������̂ŁAn���f���Ȃ�"prime", �f���łȂ��Ȃ�"not prime"�Əo�͂��Ă��������B
//�c�Ƃ������̉𓚗�ł��B

#include <iostream>
using namespace std;

int main() {
	int n;
	int i;
	
	cin >> n;
	
	for (i = 2; i < n; i++) {	//2, 3, 4, �c, n�Ŏ������� -> �ǂ�ł����肫��Ȃ���Αf��
		if (n % i == 0) {
			break;
		}
	}
	
	if (i < n) {	//i�Ŋ���؂ꂽ
		cout << "not prime" << endl;
	}
	else {			//2�`n-1�Ŋ���؂�Ȃ�����
		cout << "prime" << endl;
	}
	
	return 0;
}