//if (条件) { /*①*/ } /*②*/
//条件 == 真のとき（条件が成り立つとき）、① -> ②と実行される（ifの{}内に入る）
//条件 == 偽のとき（条件が成り立たないとき）、②と実行される（ifの{}内に入らない）

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