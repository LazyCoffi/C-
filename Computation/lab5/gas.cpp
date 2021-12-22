#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

const int N = 105;

vector<double> a[N];

int main() {
	freopen("gas.in", "r", stdin);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		a[i].push_back(0);
		for (int j = 1; j <= n + 1; j ++) {
			double x;
			cin >> x;
			a[i].push_back(x);
		}
	}

	for (int j = 1; j <= n; j ++) {
		for (int k = 1; k <= n + 1; k ++) {
			cout << a[j][k] << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	for (int i = 1; i <= n; i ++) {

		for (int j = i; j <= n; j ++) {
			if (a[i][i] < a[j][i]) swap(a[i], a[j]);
		}

		for (int j = n + 1; j >= i; j --) {
			a[i][j] /= a[i][i];
		}

		for (int j = i + 1; j <= n; j ++) {
			for (int k = n + 1; k >= i; k --) {
				a[j][k] = a[j][k] / a[j][i] - a[i][k];
			}
		}

		for (int j = 1; j <= n; j ++) {
			for (int k = 1; k <= n + 1; k ++) {
				cout << a[j][k] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	
	double x[N];
	for (int i = n; i > 0; i --) {
		x[i] = a[i][n + 1];
		for (int j = i + 1; j <= n; j ++) {
			x[i] -= a[i][j] * x[j];
		}
	}
	for (int i = 1; i <= n; i ++) {
		cout << x[i] << " ";
	}
	cout << endl;
}
