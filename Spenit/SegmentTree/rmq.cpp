//0で初期化されたN個の要素があります。Q個のクエリ（処理）が与えられるので順番に処理してください。各処理は、
//0 x y, または, 1 l r, という形式で与えられます。それぞれ
//・x(0 <= x < N)番目の要素をyにする
//・l番目からr番目(0 <= l <= r < N)の要素のうち, 最小のものを求める
//です。

//入力
//N Q
//クエリ1
//…
//クエリQ
//1 <= N <= 100000, 1 <= Q <= 100000

/*
入力例：
6 18
0 0 3
0 1 1
0 2 4
0 3 2
0 4 5
0 5 9
1 0 5
1 2 4
1 1 1
1 3 5
1 5 5
0 1 5
1 1 2
0 3 9
0 5 -1
1 0 4
1 0 5
1 1 5

出力例：
1
2
1
2
9
4
3
-1
-1
*/

#include <iostream>
using namespace std;

const int depth = 17;		//MAX_N >= 2^depth(葉の個数)を超える最小のdepth
const int INF = 1000000000;	//∞っぽい整数

class SegTree {
public:
	int data[(1 << (depth + 1))];	//本当は2^(depth + 1) - 1個で十分
	
	void init() { for (int i = 0; i < (1 << (depth + 1)); i++) data[i] = 0; }
	
	void update(int pos, int x) {
		pos = (1 << depth) - 1 + pos;	//左からpos(>=0)番目の葉のインデックス
		data[pos] = x;
		
		while (pos > 0) {
			pos = (pos - 1) / 2;									//親のindexを求める
			data[pos] = min(data[2 * pos + 1], data[2 * pos + 2]);	//更新
		}
	}
	
	//[l, r)の最小値を求める (左からl, l + 1, …, r - 1番目の葉の最小値を求める)
	int query(int l, int r, int a = 0, int b = (1 << depth), int id = 0) {
		if (r <= a || b <= l) return INF;		//区間[l, r)と区間[a, b)が重ならない
		if (l <= a && b <= r) return data[id]; 	//区間[a, b)が区間[l, r)に含まれる
		
		int u = query(l, r, a, a + (b - a) / 2, 2 * id + 1);
		int v = query(l, r, a + (b - a) / 2, b, 2 * id + 2);
		return min(u, v);
	}
};
SegTree seg;

int main() {
	seg.init();
	
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < q; i++) {
		int t, l, r;
		
		cin >> t >> l >> r;
		
		if (t == 0) {
			seg.update(l, r);
		}
		else {
			cout << seg.query(l, r + 1) << endl;
		}
	}
	return 0;
}