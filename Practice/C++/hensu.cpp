//これはコメントです
/*
	これもコメントです
*/

//変数 = 値を入れる箱
//型 = 変数に入れる値の種類 (↓型の種類）
//int…-2^31 ～ 2^31 - 1の整数, 32bit
//double…実数（正確には, 浮動小数点数）, 64bit
//char…半角文字(abcABC012_など), 8bit
//long long…-2^63～-2^63 - 1の整数, 64bit
//bool…true(真), false(偽), 8bit

//例えば、char a; とすると、半角文字を入れるための箱(名前はa)ができる。


#include <iostream>	//おまじない
using namespace std;	//std::coutをcoutと書くためのおまじない

int main() {		//プログラムはここから始まる(上から下へ実行, ;（セミコロン）が文の区切り）
	int a;
	a = 10;
	a = a + 2;	//右から評価。=は代入演算子。a <- 10 + 2となるので、aは12に書き換わる。
	cout << "a = " << a << endl;
	return 0;
}
