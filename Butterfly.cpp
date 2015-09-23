#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

struct edge {
	int v;
	bool type;
};

bool test_bipartite(const vector<vector<edge> > &lnklst) {
	int n = lnklst.size();
	vector<bool> visited(n);
	vector<bool> color(n);
	queue<int> q;
	q.push(0);
	visited[0] = 1;
	color[0] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int j = 0; j<lnklst[u].size(); j++) {
			edge e = lnklst[u][j];
			int v = e.v;
			if (!visited[v]) {
				color[v] = color[u] ^ e.type;
				q.push(v);
				visited[v] = 1;
			}
			else if (color[v] != color[u] ^ e.type) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		vector<vector<edge> > lnklst(n);
		for (int i = 0; i<m; i++) {
			int u, v, type;
			//scanf("%d %d %d", &u, &v, &type);
			cin >> u >> v >> type;
			edge e;
			e.v = v; 
			e.type = type;
			lnklst[u].push_back(e);
			e.v = u;
			lnklst[v].push_back(e);
		}

		if (test_bipartite(lnklst)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
