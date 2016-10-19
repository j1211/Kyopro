//画面から入力を受け付けます。
//余談：数は10進数で入力(cin)される。出力(cout)も10進数である。 -> ここらへんの話は分からなくて大丈夫。

#include <iostream>
using namespace std;

int main() {
	int a;	//aという箱を作る

	cin >> a;	//画面に入力した値をaに入れる

	a = a * 2;	//2倍して代入. a *= 2;と書くこともできる

	a = a + 1;	//1たして代入. a += 1, または, a++と書くこともできる

	cout << a << endl;
	return 0;
}