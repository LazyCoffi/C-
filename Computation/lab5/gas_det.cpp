#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;
const int N = 1005;

vector<double> det[N];

int main() {
	freopen("gas_det.in", "r", stdin);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		det[i].push_back(0);
		for (int j = 1; j <= n; j ++) {
			double x;
			cin >> x;
			det[i].push_back(x);
		}
	}
	
	double res = 1;
	for (int i = 1; i <= n; i ++) {
		for (int j = i + 1; j <= n; j ++) {//求主元
			if (det[j][i] > det[i][i]) {
				swap(det[j], det[i]);
				res *= -1;//行列式交换结果乘以-1
			}
		}

		for (int j = i + 1; j <= n; j ++) {//消元
			for (int k = n; k >= i + 1; k --) {
				det[j][k] = det[j][k] - det[i][k] / det[i][i] * det[j][i];
			}
		}

		res *= det[i][i];//累计答案
	}
	
	cout << res << endl;
}
