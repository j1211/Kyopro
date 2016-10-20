/*2つの値を交換*/

#include <iostream>
using namespace std;

int main() {
	int a, b;
	int t;

	cin >> a >> b;
	
	t = a;	//t <- old_a
	a = b;	//a <- old_b
	b = t;	//b <- old_a

	cout << a << " " << b << endl;
	return 0;
}


//動作例 (入力が「5 3」のとき）
//10行目終了：a == 5, b == 3, t == ?
//12行目終了：a == 5, b == 3, t == 5
//13行目終了：a == 3, b == 3, t == 5
//14行目終了：a == 3, b == 5, t == 5
