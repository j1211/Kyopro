//�����Ȑ���a�ɂ���, x�ȏ�̍ŏ��̃C���f�b�N�X��Ԃ��B(�擪��0�ԂƂ���)
//��: a = {3, 4, 5, 5, 6, 7}, x = 5�̂Ƃ�, 2��Ԃ��B

#include <iostream>
using namespace std;

/*��O(n). �x��.
int lower_bound(int n, int a[], int x) {
	for (int i = 0; i < n; i++) {
		if (a[i] >= x) {
			return i;
		}
	}
	return n;
}*/

/*2���T��O(logn). ����.*/
int lower_bound(int n, int a[], int x) {
	int st = -1, ed = n, mid; //xxxooo, (st, ed]
	
	while (ed - st >= 2) {
		mid = (st + ed) / 2;
		if (a[mid] >= x) {	//mid�������荶
			ed = mid;
		}
		else {				//mid���E
			st = mid;
		}
	}
	return ed;
}

int main() {
	int n, a[100];
	int q;
	int x;
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];	//�����������珇�ɓ���Ă��������i�����l��OK)
	
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> x;
		cout << "x�ȏ�̍ŏ��v�f��" << "a[" << lower_bound(n, a, x) << "] = " << a[lower_bound(n, a, x)] << "�ł��B" << endl;
	}
	return 0;
}