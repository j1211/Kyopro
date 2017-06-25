//関数とは…一連の処理をまとめて記述したもの。値を渡したり返したりできる。これを上手く使うと, プログラムを簡単に書けます。(mainは直感的に, hoge()とかは単純に書ける）
//C++の関数（大きく分けて4パターン）
//                処理：void hoge() { B;C;D; } int main() { A; hoge(); E; } のように書くと, プログラムはABCDEの順で処理します。
//        戻り値＋処理：int fuga() { B;C;D; return 10; } int main() { int a = fuga(); } のように書くと, プログラムはB,C,Dを実行した後, aに10 (dispがreturnした値)が代入されます。
//          引数＋処理：void disp(int a) { printf("%d\n", a); } int main() { disp(10); }のように書くと, プログラムは10を表示します。(dispのaに10を代入→disp内を実行）
//  引数＋戻り値＋処理；サンプルで書きます。

#include <iostream>
using namespace std;

int func(int n) {
	for (int i = 0; i < n * n; i++) { cout << "o"; }
}

int main() {
	return 0;
}
