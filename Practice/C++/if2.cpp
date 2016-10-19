//これは成績判定です。80以上でGreat, 60以上でGood, 50以上でOk, 49以下でfail

#include <iostream>
using namespace std;

int main() {
	int score;

	cin >> score;
	
	if (score >= 80) {
		cout << "Great" << endl;
	}
	else if (score >= 60) {
		cout << "Good" << endl;
	}
	else if (score >= 50) {
		cout << "Ok" << endl;
	}
	else {
		cout << "fail" << endl;
	}
	cout << "判定終了" << endl;
	return 0;
}

//if … もし, else if … それ以外でもし, else … それ以外
//if (A) { /*①*/ } else if (B) { /*②*/ } else { /*③*/ } /*④*/
//という風に書かれたプログラムを実行すると…

//Aが成立するなら① -> ④の順で実行される。
//Aが成立せずBが成立するなら② -> ④の順で実行される
//AもBも成立しなければ③ -> ④の順で実行される。

//最後のelseは書かなくてもよいし、else ifが2つ以上あってもよい
//また、if (A) { } else { } という書き方も可能