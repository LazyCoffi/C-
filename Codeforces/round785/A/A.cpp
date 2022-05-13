#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    freopen("i.in", "r", stdin);

    int t;
    cin >> t;
    while (t --) {
        string s;
        cin >> s;
        int len = s.size();
        int sum = 0;

        if (len == 1) {
            cout << "Bob " << s[0] - 'a' + 1 << endl;
            continue;
        }

        cout << "Alice ";

        for (int i = 0; i < len; i ++) {
            sum += s[i] - 'a' + 1;
        }


        if (len & 1) {
            cout << (s[0] < s[len - 1] ? sum - 2 * (s[0] - 'a' + 1) : sum - 2 * (s[len - 1] - 'a' + 1)) << endl;
        }
        else {
            cout << sum << endl;
        }
    }
}
