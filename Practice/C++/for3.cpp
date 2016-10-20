//for文もbreakで抜けることができます。
//breakで抜けられるfor文は1つであることに注意してください。

//内容はfor2.cppと同じで、縦5 * 横10の長方形の表示、となっております

#include <iostream>
using namespace std;

int main() {
	int h = 5, w = 10;
	int i, j;
	
	for (i = 0; i < h; i++) {
		for (j = 0; ; j++) {
			if (j >= w) {
				break;
			}
			cout << "o";
		}
		cout << endl;
	}
	
	return 0;
}