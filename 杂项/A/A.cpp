#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int m[11][9] = {{1, 1, 1, 0, 1, 1, 1}, 
                {0, 0, 1, 0, 0, 1, 0},
                {1, 0, 1, 1, 1, 0, 1},
                {1, 0, 1, 1, 0, 1, 1},
                {0, 1, 1, 1, 0, 1, 0},
                {1, 1, 0, 1, 0, 1, 1},
                {1, 1, 0, 1, 1, 1, 1},
                {1, 0, 1, 0, 0, 1, 0},
                {1, 1, 1, 1, 1, 1, 1},
                {1, 1, 1, 1, 0, 1, 1},
                {0, 0, 0, 0, 0, 0, 0}};

int cnt(int a, int b) {
   int tot = 0;
   for (int i = 0; i < 7; i ++) {
       tot += abs(m[a][i] - m[b][i]);
   }
   return tot;
}

int main() {
    string s;
    cin >> s;
    int k = 10, len = s.size(), ans = 0;
    for (int i = 0; i < len; i ++) {
        ans += cnt(s[i] - '0', k);
        k = s[i] - '0';
    }

    cout << ans << endl;
}
