//0�ŏ��������ꂽN�̗v�f������܂��BQ�̃N�G���i�����j���^������̂ŏ��Ԃɏ������Ă��������B�e�����́A
//0 x y, �܂���, 1 l r, �Ƃ����`���ŗ^�����܂��B���ꂼ��
//�Ex(0 <= x < N)�Ԗڂ̗v�f��y�ɂ���
//�El�Ԗڂ���r�Ԗ�(0 <= l <= r < N)�̗v�f�̂���, �ŏ��̂��̂����߂�
//�ł��B

//����
//N Q
//�N�G��1
//�c
//�N�G��Q
//1 <= N <= 100000, 1 <= Q <= 100000

/*
���͗�F
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

�o�͗�F
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

const int depth = 17;		//MAX_N >= 2^depth(�t�̌�)�𒴂���ŏ���depth
const int INF = 1000000000;	//�����ۂ�����

class SegTree {
public:
	int data[(1 << (depth + 1))];	//�{����2^(depth + 1) - 1�ŏ\��
	
	void init() { for (int i = 0; i < (1 << (depth + 1)); i++) data[i] = 0; }
	
	void update(int pos, int x) {
		pos = (1 << depth) - 1 + pos;	//������pos(>=0)�Ԗڂ̗t�̃C���f�b�N�X
		data[pos] = x;
		
		while (pos > 0) {
			pos = (pos - 1) / 2;									//�e��index�����߂�
			data[pos] = min(data[2 * pos + 1], data[2 * pos + 2]);	//�X�V
		}
	}
	
	//[l, r)�̍ŏ��l�����߂� (������l, l + 1, �c, r - 1�Ԗڂ̗t�̍ŏ��l�����߂�)
	int query(int l, int r, int a = 0, int b = (1 << depth), int id = 0) {
		if (r <= a || b <= l) return INF;		//���[l, r)�Ƌ��[a, b)���d�Ȃ�Ȃ�
		if (l <= a && b <= r) return data[id]; 	//���[a, b)�����[l, r)�Ɋ܂܂��
		
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