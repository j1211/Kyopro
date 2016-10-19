//if (条件) { /*1*/ } /*2*/
//条件 == 真のとき（条件が成り立つとき） 1 -> 2の順で実行される（ifの{}内に入る）
//条件 == 偽のとき（条件が成り立たないとき）、2の順で実行される（ifの{}内に入らない）

#include <iostream>
using namespace std;

int main() {
	int a, b;

	cin >> a >> b;

	if (a > b) {
		cout << "aはbと等しいです" << endl;
	}
	cout << "a = " << a << " b = " << b << endl;

	return 0;
}