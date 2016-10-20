//10^8以下の整数nが与えられるので、nが素数なら"prime", 素数でないなら"not prime"と出力してください。
//…という問題の解答例です。

#include <iostream>
using namespace std;

int main() {
	int n;
	int i;
	
	cin >> n;
	
	for (i = 2; i < n; i++) {	//2, 3, 4, …, nで試し割り -> どれでも割りきれなければ素数
		if (n % i == 0) {
			break;
		}
	}
	
	if (i < n) {	//iで割り切れた
		cout << "not prime" << endl;
	}
	else {			//2～n-1で割り切れなかった
		cout << "prime" << endl;
	}
	
	return 0;
}