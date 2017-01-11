//無向木の葉(id, 1-indexed)を昇順で列挙する。
/*
入力例：
6
1 2
2 4
4 3
4 5
1 6

出力例：
3
5
6

説明：
1 - 2 - 4 - 3
|       |
  - 6     - 5
こういう木を考えている。
制約：
2 <= 頂点数 <= 100000
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> et[100000];
vector<int> ans;

void dfs(int parent, int v) {
	if (et[v].size() == 1 && parent != -1) {
		ans.push_back(v);
	}
	for (int i = 0; i < et[v].size(); i++) {
		if (et[v][i] == parent) continue;
		dfs(v, et[v][i]);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int from, to;
		cin >> from >> to;
		from--;
		to--;
		et[from].push_back(to);
		et[to].push_back(from);
	}
	dfs(-1, 0);
	
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) cout << ans[i] + 1 << endl;
	return 0;
}