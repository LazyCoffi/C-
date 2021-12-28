#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

double TZ = 1e-16;

double f_(double x) {
	return 3 * x * x - 1;
}

double f(double x) {
	return x * x * x - x - 1;
}

int main() {
	freopen("newton.in", "r", stdin);

	double x, eps;
	int n, m;

	cin >> x >> eps >> n >> m;
	
	for (int i = 0; i < n; i ++) {
		if (abs(f_(x)) < TZ) {
			cout << "奇异" << endl;
			return 0;
		}

		double lamda = 1;
		double x_ = x - lamda * f(x) / f_(x);
		int cnt = 0;

		for (;cnt < m && abs(f(x_)) > abs(f(x)); 	
			 cnt ++, lamda *= 0.5, x_ = x - lamda * f(x) / f_(x));

		if (cnt >= m) {
			cout << "请重新输入x0" << endl;
			return 0;
		}

		if (abs(x - x_) < eps) {
			cout << "x: " << x << endl;
			return 0;
		}

		x = x_;
		cout << "中间x: " << x << endl;
	}

	cout << "迭代失败" << endl;
}
