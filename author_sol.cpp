#include <bits/stdc++.h>

using namespace std;

void DFS(int p, int d, int &ans, vector<int> v[]) {
	// store the minimum number of groups formed
	ans = max(ans, d);
	for (int i = 0; i < (int) v[p].size(); i++) {
		// visit the all the connected nodes recursively
		DFS(v[p][i], d + 1, ans, v);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	// view the image in this repository for better understanding
	// use DFS (Depth-First Search) to solve this problem
	vector<int> v[n + 1];
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		if (p == -1) {
			// ignore the value of '-1' (root)
			continue;
		}
		// insert the 'i + 1' values using 'p' as its index
		v[p].emplace_back(i + 1);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		// visit all the connected nodes using this function
		DFS(i + 1, 1, ans, v);
	}
	cout << ans << '\n';
	return 0;
}
