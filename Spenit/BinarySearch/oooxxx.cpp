//f(x)…あるtについて{x <= t ⇒ f(x) = 1, x > t ⇒ f(x) = 0}となる関数。
//要するに…f(0,1,2,3,4,5,6,7) = ooooxxxxみたいな関数。
//求めるもの…f(n) = 1となる最大の整数n
#include <iostream>
using namespace std;

int t;	//入力制約：1 <= t <= 11

//今回は連続関数だが, 不連続でも, 整数座標でしか定義されない関数でも構わない。
int f(int x) {
	int cnt = 0;
	while (x > 0) { x /= (cnt + 2); cnt++; }
	if (cnt <= t) return 1;
	else return 0;
}

int main() {
	cin >> t;
	
	int st = 0, ed = 1000000000, mid;	//[st, ed) … 答えはst以上, ed未満
	while (ed - st >= 2)
	{
		mid = (st + ed) / 2;
		if (f(mid) == 1) {	//答えはmid以上
			st = mid;
		}
		else {				//答えはmid未満
			ed = mid;
		}
	}
	
	cout << st << endl;
	return 0;
}