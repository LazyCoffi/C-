#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 105;

double a[N][N];

int main() {
	freopen("gauss.in", "r", stdin);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n + 1; j ++) {
			cin >> a[i][j];
		}
	}

	double x[N];
	for (int i = 1; i <= n; i ++) {
		cin >> x[i];
	}

	double eps;
	cin >> eps;
	
	for (int p = 1; p <= m; p ++) {
		double maxeps = 0;
		double x_[N];
		for (int i = 1; i <= n; i ++) {
			if (a[i][i] == 0) continue;
			double res = a[i][n + 1] / a[i][i];
			for (int j = 1; j <= n; j ++) {
				if (i == j) continue;
				res -= a[i][j] * x[j] / a[i][i];
			}
			x_[i] = res;
		}
		
		for (int i = 1; i <= n; i ++) {
			maxeps = max(maxeps, abs(x[i] - x_[i]));
			x[i] = x_[i];
		}

		for (int i = 1; i <= n; i ++) cout << x[i] << " ";
		cout << endl;

		if (maxeps < eps) break;
	}
}
