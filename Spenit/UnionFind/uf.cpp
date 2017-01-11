//問題：
//N個の部活(部活0～部活N-1)があります。今からQ回, 合併か調査が行われます。
//i(1 <= i <= Q)回目に行う操作は, 3つの整数Ti, Ai, Biで表されます。
//・Ti = 0のとき, 部活Aiと部活Biを合併します。
//・Ti = 1のとき, 部活Aiと部活Biが合併されているかを調査します。されていれば1, されていなければ0を答えてください。
//入力：
//N Q
//T1 A1 B1
//…
//TQ AQ BQ
//制約
//1 <= N <= 100000, 1 <= Q <= 100000
//
/*
 入力例：
6 11
1 1 2
0 1 2
1 1 2
0 3 4
0 2 3
1 1 4
0 4 6
0 2 6
1 3 5
0 2 5
1 3 5
//出力例：
0
1
1
0
1
*/

#include <iostream>
using namespace std;

//低速なUnionFind, rootを求めるのに最悪O(N)かかる。
class UnionFind {
	int parent[100000];
public:
	void init() { for (int i = 0; i < 100000; i++) parent[i] = i; }
	int root(int x) { if (parent[x] == x) return x; return root(parent[x]); }		//return parent[x] = root(parent[x]);と書き換える(経路圧縮する)と, 最悪O(logN)になって高速
	void marge(int x, int y) { x = root(x); y = root(y); if (x != y) parent[x] = y; }
	bool is_same(int x, int y) { if (root(x) == root(y)) return true; return false; }
};
UnionFind uf;

int main() {
	uf.init();
	
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < q; i++) {
		int t, a, b;
		cin >> t >> a >> b;
		
		if (t == 0) {
			uf.marge(a, b);
		}
		else {
			cout << uf.is_same(a, b) << endl;
		}
	}
	return 0;
}