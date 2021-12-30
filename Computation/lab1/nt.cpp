#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int N = 505;

double x[N], y[N], f[N][N];

int main() {
	freopen("nt.in", "r", stdin);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++) {//输入数据
		cin >> x[i] >> y[i];
		f[0][i] = y[i];
	}

	for (int i = 1; i < n; i ++) {//构造差商表
		for (int j = i + 1; j <= n; j ++) {
			f[i][j] = (f[i - 1][j] - f[i - 1][j - 1]) / (x[j] - x[j - i]);
		}
	}

	double x0;
	cin >> x0;
	double ans = 0;
	for (int i = 0; i < n; i ++) {//构造插值多项式
		double res = 0;
		res = f[i][i + 1];	
		for (int j = 1; j <= i; j ++) {
			res *= x0 - x[j];
		}
		ans += res;
	}
	cout << ans << endl;
}
