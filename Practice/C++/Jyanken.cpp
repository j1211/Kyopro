/*hello.cpp, hensu.cppは読んでおいた方がよいかも…*/
//じゃんけんゲームです。グー(0), チョキ(1), パー(2)を2人が出して対戦します。
//なお、if文は多重化(=ネスト)できます。というか{}を使う構文は大抵多重化できる。

//もっと賢く書けますが、あえて長く書いています。

#include <iostream>
using namespace std;

int main() {
	int a, b;

	cout << "じゃんけんゲーム" << endl;	//;が命令の区切り(1行). endlは改行.
	cout << "Aさんの手(0～2) > "; cin >> a;
	cout << "Bさんの手(0～2) > "; cin >> b;

	if (a == 0) {
		if (b == 0) {
			cout << "グーとグーであいこ！" << endl;
		}
		else if (b == 1) {
			cout << "グーとチョキでAの勝ち" << endl;
		}
		else {
			cout << "グーとパーでBの勝ち" << endl;
		}
	}

	else if (a == 1) {
		if (b == 0) {
			cout << "チョキとグーでBの勝ち" << endl;
		}
		else if (b == 1) {
			cout << "チョキとチョキであいこ!" << endl;
		}
		else {
			cout << "チョキとパーでAの勝ち" << endl;
		}
	}

	else {
		if (b == 0) {
			cout << "パーとグーでAの勝ち" << endl;
		}
		else if (b == 1) {
			cout << "パーとチョキでBの勝ち" << endl;
		}
		else {
			cout << "パーとパーであいこ!" << endl;
		}
	}
	
	return 0;
}