#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int t, ans = 0;
	cin >> t;
	while (t --) {
		int x;
		cin >> x;
		if (x & 4 || x & 8) ans ++;
	}
	cout << ans << endl;
} 
