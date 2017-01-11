//f(x)�c����t�ɂ���{x <= t �� f(x) = 1, x > t �� f(x) = 0}�ƂȂ�֐��B
//�v����Ɂcf(0,1,2,3,4,5,6,7) = ooooxxxx�݂����Ȋ֐��B
//���߂���́cf(n) = 1�ƂȂ�ő�̐���n
#include <iostream>
using namespace std;

int t;	//���͐���F1 <= t <= 11

//����͘A���֐�����, �s�A���ł�, �������W�ł�����`����Ȃ��֐��ł��\��Ȃ��B
int f(int x) {
	int cnt = 0;
	while (x > 0) { x /= (cnt + 2); cnt++; }
	if (cnt <= t) return 1;
	else return 0;
}

int main() {
	cin >> t;
	
	int st = 0, ed = 1000000000, mid;	//[st, ed) �c ������st�ȏ�, ed����
	while (ed - st >= 2)
	{
		mid = (st + ed) / 2;
		if (f(mid) == 1) {	//������mid�ȏ�
			st = mid;
		}
		else {				//������mid����
			ed = mid;
		}
	}
	
	cout << st << endl;
	return 0;
}