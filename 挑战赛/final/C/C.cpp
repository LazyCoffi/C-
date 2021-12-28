#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 1e5 + 7;

int p[N];
int n, m, L;

int main() {
	freopen("C.in", "r", stdin);

	cin >> L >> n >> m;
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &p[i]);
	}
	p[n + 1] = L;

	sort(p + 1, p + n + 2);

	priority_queue<int, vector<int>, greater<> > ori_blocks;
	for (int i = 1; i <= n + 1; i ++) {
		ori_blocks.push(p[i] - p[i - 1] + 1);
	}
	
	int l = 0, r = L, mid;
	while (l <= r) {
		mid = l + (r - l) / 2;
		priority_queue<int, vector<int>, greater<> > que = ori_blocks;
		int i;
		for (i = 1; i <= m; i ++) {
			int len = que.top();
			if (len < mid) break;
			que.pop();
			que.push(len / 2);
			que.push(len / 2 + (len & 1));
		}
		if (i >= m) l = mid + 1;
		else r = mid - 1;	
	}
	cout << mid << endl;
}
