//whileの途中( = {}の中) でループから抜けたい場合は、breakを使います。

//これは、0から9までを出力するコードです。 ちなみにbreakしないと、無限ループになります。

#include <iostream>
using namespace std;

int main() {
	int i;
	
	i = 0;
	while (true) {	//条件式は常に真
		cout << i << endl;
		i++;
		if (i >= 10) {
			break;
		}
	}
	
	return 0;
}


//余談：
//if, whileなどの制御文において、{}の中が1行だけなら{}を省略することができます。
//例えば、15～17行目を：
//if (i >= 10) break;
//と書くこともできる。
