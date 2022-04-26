#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        bool f[35][35] = {false};
        f[0][0] = true;

        auto match=[&](int i, int j) {
            if (i == 0) return false;
            if (p[j - 1] == '.') return true;
            return s[i - 1] == p[j - 1];
        };

        for (int i = 0; i <= n; i ++) {
            for (int j = 1; j <= m; j ++) {
                if (p[j - 1] == '*') {
                    f[i][j] |= f[i][j - 2];
                    if (match(i, j - 1)) {
                        f[i][j] |= f[i - 1][j];
                    }
                }
                else {
                    if (match(i, j)) {
                        f[i][j] |= f[i - 1][j - 1];
                    }
                }
            }
        }
        return f[n][m];
    }
};

int main() {

    Solution *sol = new Solution();
    string s = "ab";
    string p = ".*";
    if (sol->isMatch(s, p)) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
}
