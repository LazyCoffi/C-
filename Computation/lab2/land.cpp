#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const int N = 10005;
double x[N], y[N], y_[N];

int n;

int main() {
	freopen("map.in", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> x[i];
		x[i] = x[i] * 40 / 18;
	}
	for (int i = 1; i <= n; i ++) {
		cin >> y[i];
		y[i] = y[i] * 40 / 18;
	}

	for (int i = 1; i <= n; i ++) {
		cin >> y_[i];
		y_[i] = y_[i] * 40 / 18;
	}

	double upperS = 0, lowerS = 0;	

	for (int i = 1; i < n; i ++) {
		double h = x[i + 1] - x[i];
		lowerS += (y[i + 1] + y[i]) * h / 2;
		upperS += (y_[i + 1] + y_[i]) * h / 2;
	}
	cout << upperS - lowerS << endl;
}
