//for文も多重化(=ネスト)できます.

#include <iostream>
using namespace std;

int main() {
	int h = 5, w = 10;
	int i, j;
	
	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			cout << "o";
		}
		cout << endl;
	}
	
	return 0;
}