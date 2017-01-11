//���F
//N�̕���(����0�`����N-1)������܂��B������Q��, �������������s���܂��B
//i(1 <= i <= Q)��ڂɍs�������, 3�̐���Ti, Ai, Bi�ŕ\����܂��B
//�ETi = 0�̂Ƃ�, ����Ai�ƕ���Bi���������܂��B
//�ETi = 1�̂Ƃ�, ����Ai�ƕ���Bi����������Ă��邩�𒲍����܂��B����Ă����1, ����Ă��Ȃ����0�𓚂��Ă��������B
//���́F
//N Q
//T1 A1 B1
//�c
//TQ AQ BQ
//����
//1 <= N <= 100000, 1 <= Q <= 100000
//
/*
 ���͗�F
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
//�o�͗�F
0
1
1
0
1
*/

#include <iostream>
using namespace std;

//�ᑬ��UnionFind, root�����߂�̂ɍň�O(N)������B
class UnionFind {
	int parent[100000];
public:
	void init() { for (int i = 0; i < 100000; i++) parent[i] = i; }
	int root(int x) { if (parent[x] == x) return x; return root(parent[x]); }		//return parent[x] = root(parent[x]);�Ə���������(�o�H���k����)��, �ň�O(logN)�ɂȂ��č���
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