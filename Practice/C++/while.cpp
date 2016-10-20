//while (条件式) { /*条件が真のときの処理*/ }	//}まで来たら「条件式」まで戻る
//つまり、条件式が成り立つ間は, whileの中をぐるぐる回ります。

#include <iostream>
using namespace std;

int main() {
	int i = 0;
	
	while (i < 10) {
		cout << i << endl;	//iの値を出力する.
		i = i + 1;			//iの値を1増やす. i++;と書いてもよい。
	}
	
	cout << "while文を抜けました。i = " << i << endl;
	
	return 0;
}
