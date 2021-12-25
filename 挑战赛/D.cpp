#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1005;

int sum[N][N];

int main() {
	int n, k;	
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			int x;
			scanf("%d", &x);
			sum[i][j] = x + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1]; 
		}
	}
	
	int ans = 0;
	for (int i = k; i <= n; i ++) {
		for (int j = k; j <= n; j ++) {
			int x = i - k, y = j - k;
			ans = max(ans, sum[i][j] - sum[x][j] - sum[i][y] + sum[x][y]);
		}
	}
	
	cout << ans << endl;
} 
