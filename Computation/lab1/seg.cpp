#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 5000;

double x[N], y[N];

double f(double x) {//设置函数
	return 1.0 / (1 + x * x);
}

int main() {
	freopen("i.in", "r", stdin);
	int n;
	double l, r;
	cin >> l >> r >> n;
	double c = (r - l) / double(n);
	for (int i = 0; i <= n; i ++) {
		x[i] = l + i * c;//构造等距插值点
		y[i] = f(x[i]);//求值
	}
	
	int m;
	cin >> m;
	while(m --) {
		double x0;
		cin >> x0;

		double ans = 0;
		for (int i = 0; i <= n; i ++) {
			double res = y[i];
			for (int j = (i + 1) % (n + 1); j != i; j = (j + 1) % (n + 1)) {//构造多项式
				res = res * (x0 - x[j]) / (x[i] - x[j]);
			}
			ans += res;
		}
		cout << ans << endl;//输出答案
	}
}
