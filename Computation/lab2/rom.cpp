#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

double l, r, eps;
vector<double> T, S, C, R;

double f(double x) {
	if (x == 0) return 1;
	return sin(x) / x;
}

void add_T() {
	int k = T.size();
	int n = (1 << (k - 1));
	double res = 0;
	double h = (r - l) / n;
	for (int i = 0; i < n; i ++) {
		double xk = l + (2 * i + 1) * h / 2;	
		res += f(xk);
	}
	res *= h / 2;
	res += 0.5 * T[k - 1];
	cout << res << endl;
	T.push_back(res);
}

void add_S() {
	while (T.size() <= S.size() + 1) add_T();
	int n = T.size() - 1;
	S.push_back((4 * T[n] - T[n - 1]) / 3);
}

void add_C() {
	while (S.size() <= C.size() + 1) add_S();
	int n = S.size() - 1;
	C.push_back((16 * S[n] - S[n - 1]) / 15);
}

void add_R() {
	while (C.size() <= R.size() + 1) add_C();
	int n = C.size() - 1;
	R.push_back((64 * C[n] - C[n - 1]) / 63);
}

int main() {
	freopen("rom.in", "r", stdin);
	cin >> l >> r >> eps;
	T.push_back(0.5 * (r - l) * (f(l) + f(r)));
	add_R(); add_R();
	for (int i = 1; abs(R[i] - R[i - 1]) > eps; add_R(), i ++);
	cout << "T: ";
	for (double t : T) cout << t << " ";
	cout << endl;
	cout << "S: ";
	for (double s : S) cout << s << " "; 
	cout << endl;
	cout << "C: ";
	for (double c : C) cout << c << " "; 
	cout << endl;
	cout << "R: ";
	for (double r : R) cout << r << " ";
	cout << endl;
	cout << "result: " << R.back() << endl;
}
