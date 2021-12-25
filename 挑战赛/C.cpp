#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
	int k;
	string a, b;
	char _;
	cin >> k >> b;
	_ = getchar();
	getline(cin, a);
	int alen = a.size(), blen = b.size(), cnt = 0, F = 1;
	for (int i = 0; i < alen - blen; i ++) {
		int flag = 1;
		for (int j = i; j < i + blen; j ++) {
			if (a[j] != b[j - i]) {
				flag = 0;
				break;
			}
		}
		
		if (flag == 1) cnt ++;
		
		if (cnt == k) {
			for (int j = i; j < i + blen; j ++) {
				if (a[j] == 'a' || a[j] == 'A') a[j] = a[j] + 25;
				else a[j] = a[j] - 1;
			}
			F = 0;
			break;
		}
	}
	if (F) cout << "F" << endl;
	else cout << a << endl;
}
