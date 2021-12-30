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
		if (abs(f_(x)) < TZ) {//f'(x) == 0时，输出奇异标志
			cout << "奇异" << endl;
			return 0;
		}

		double lamda = 1;
		double x_ = x - lamda * f(x) / f_(x);
		int cnt = 0;

		for (;cnt < m && abs(f(x_)) > abs(f(x)); 	
			 cnt ++, lamda *= 0.5, x_ = x - lamda * f(x) / f_(x));//下山

		if (cnt >= m) {//若下山次数超过m则重新选择x0
			cout << "请重新输入x0" << endl;
			return 0;
		}

		if (abs(x - x_) < eps) {//精度达到要求则输出
			cout << "x: " << x << endl;
			return 0;
		}

		x = x_;
		cout << "中间x: " << x << endl;
	}

	cout << "迭代失败" << endl;//超过迭代次数则迭代失败
}
