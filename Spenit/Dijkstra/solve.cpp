#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#define int long long
using namespace std;

int n, m;
vector<int> et[1000];	//et[i] = 頂点iから直接行ける頂点の集合
vector<int> ec[1000];	//ec[i] = i->et[i][j]のコスト

void input() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int from, to, cst;
		cin >> from >> to >> cst;
		from--;
		to--;
		et[from].push_back(to);
		et[to].push_back(from);
		ec[from].push_back(cst);
		ec[to].push_back(cst);
	}
}

int INF = 1145141919;
int minCost[1000];

void dijkstra(int s) {
	int i;
	for (i = 0; i < n; i++) minCost[i] = INF;

	typedef pair<int, int> P;	//cst, pos
	priority_queue<P, vector<P>, greater<P> > que;

	que.push(P(0, s));
	while (!que.empty()) {
		P now = que.top();
		que.pop();
		int cst = now.first;
		int pos = now.second;

		if (minCost[pos] <= cst) continue;
		minCost[pos] = cst;

		for (int i = 0; i < et[pos].size(); i++) {
			que.push(P(cst + ec[pos][i], et[pos][i]));
		}
	}
}

signed main() {
	input();
	dijkstra(0);
	cout << minCost[n - 1] << endl;
	return 0;
}