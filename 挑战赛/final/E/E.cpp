#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 200005;

int n;
double L, v;
double p[N], sum[N];

int main() {
	freopen("E.in", "r", stdin);
	cin >> n >> L >> v;
	for (int i = 1; i <= n; i ++) {
		scanf("%lf", &p[i]);
		p[i] /= v;
	}
	L /= v;
	sum[0] = L;
	sort(p, p + n + 1);
	for (int i = 1, j = n; i <= n; i ++, j --) {
		sum[i] = sum[i - 1] + p[j];
	}
	int m;
	cin >> m;
	while (m --) {
		ll t;
		scanf("%lld", &t);
		int ans = upper_bound(sum, sum + n + 1, t) - sum;
		if (ans > n) cout << -1 << endl;
		else printf("%d\n", ans);
	}
}
