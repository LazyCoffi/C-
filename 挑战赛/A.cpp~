#include <iostream>
#include <cstdio>

using namespace std;

int f(int a, int b, int ch) {
	if (ch == '+') return a + b;
	if (ch == '*') return a * b;
	if (ch == '%') return a % b;
}

int main() {
	int a, b, c, t;
	char x, y;
	cin >> t;
	while (t --) {
		int res = 0;
		cin >> a >> x >> b >> y >> c;
		if (x != '+') {
			res = f(f(a, b, x), c, y);
		}  
		else {
			res = f(a, f(b, c, y), x);
		}
		cout << res << endl;
	}
}
