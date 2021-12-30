#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

double f(double x, double y) {
	return y - 2 * x / y;
}

double f1(double x, double y) {
	return 8 - 3 * y;
}

double f2(double x, double y) {
	return -y + x + 1;
}

int main() {
	freopen("euler.in", "r", stdin);
	double l, r, x, y;
	int n;
	cin >> l >> r >> y >> n;
		
	x = 0;
	double h = (r - l) / n;
	for (int i = 1; i <= n; i ++) {
		double x_, y_;
		double k1, k2, k3, k4;//依次构造k1,k2,k3,k4并加权平均
		x_ = x + h;
		k1 = f(x, y);
		k2 = f(x + 0.5 * h, y + 0.5 * h * k1);
		k3 = f(x + 0.5 * h, y + 0.5 * h * k2);
		k4 = f(x + h, y + h * k3);
		y_ = y + h / 6 * (k1 + 2 * k2 + 2 * k3 + k4);
		cout << "y" << i << " = " << y_ << endl;
		x = x_, y = y_;
	}
}
