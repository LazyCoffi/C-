#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

double f(double x, double y) {
	return y - 2 * x / y;
}

double f_1(double x, double y) {
	return - y + x + 1;
}

int main() {
	freopen("euler.in", "r", stdin);
	int n;
	double l, r, x, y;
	cin >> l >> r >> y >> n;
	
	double h = (r - l) / n;
	x = l;
	for (int i = 1; i <= n; i ++) {
		double x_ = x + h;
		double f0 = f_1(x, y);
		double y_ = y + h * f0;
		double f1 = f_1(x_, y_);
		y = y + h / 2 * (f0 + f1);
		cout << "y" << i << " = " << y_ << endl;
		x = x_, y = y_;
	}
}
