#include <iostream>
using namespace std;

bool isRev(int x) {
	int t = 0;
	int num[10];
	while (x) {
		num[++ t] = x % 10;
		x /= 10;
	}
	int l = 1, r = t;
	while (l <= r) {
		if (num[l] != num[r]) return 0;
		l ++, r --;
	}

	return 1;
}

int main() {
	freopen("B.in", "r", stdin);
	int L, R, K, ans = 0;
	cin >> L >> R >> K;
	while (L % K != 4) L ++;
	for (int i = L; i <= R; i += K) {
		if (isRev(i)) ans ++;
	}
	cout << ans << endl;
}
