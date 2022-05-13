#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main() {
    freopen("i.in", "r", stdin);

    int t;
    cin >> t;
    while (t --) {
        string s;
        cin >> s;
        int len = s.size();
        int alphabet[27] = {0};
        int cnt = 0, flag = 1;
        for (int i = 0; i < len; i ++) {
            if (alphabet[s[i] - 'a'] == 0) {
                cnt ++;
                alphabet[s[i] - 'a'] = -1;
            }
        }

        for (int i = 0; i < len; i ++) {
            if (alphabet[s[i] - 'a'] != -1 && i - alphabet[s[i] - 'a'] - 1 < cnt - 1) {
                flag = 0;              
                break;
            }
            alphabet[s[i] - 'a'] = i;
        }

        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
