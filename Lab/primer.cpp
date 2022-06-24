#include <iostream>
using namespace std;
int main() {
	int n, m, sum = 0;
	cin >> m >> n;
	for (int i = m; i <= n; i ++) {
		int acc = 1;
		for (int j = 2; j < i; j ++) {
			if (i % j == 0) acc = 0;
		}
		sum += acc;
	}

	cout << "num=" << sum << endl;
}
