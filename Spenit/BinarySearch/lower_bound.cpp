//昇順な数列aについて, x以上の最小のインデックスを返す。(先頭は0番とする)
//例: a = {3, 4, 5, 5, 6, 7}, x = 5のとき, 2を返す。

#include <iostream>
using namespace std;

/*愚直O(n). 遅い.
int lower_bound(int n, int a[], int x) {
	for (int i = 0; i < n; i++) {
		if (a[i] >= x) {
			return i;
		}
	}
	return n;
}*/

/*2分探索O(logn). 速い.*/
int lower_bound(int n, int a[], int x) {
	int st = -1, ed = n, mid; //xxxooo, (st, ed]
	
	while (ed - st >= 2) {
		mid = (st + ed) / 2;
		if (a[mid] >= x) {	//midかそれより左
			ed = mid;
		}
		else {				//midより右
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
	for (int i = 0; i < n; i++) cin >> a[i];	//小さい方から順に入れてください（同じ値はOK)
	
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> x;
		cout << "x以上の最小要素は" << "a[" << lower_bound(n, a, x) << "] = " << a[lower_bound(n, a, x)] << "です。" << endl;
	}
	return 0;
}