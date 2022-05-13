#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 40004, M = 502, MOD = 1e9 + 7;

int reverse(int x) {
    int y = 0;
    while (x) {
        y = y * 10 + x % 10;
        x /= 10;
    }
    return y;
}

int f[N][M] = {0};

int main() {
    freopen("i.in", "r", stdin);

    vector<int> pal;
    pal.push_back(0);

    for (int i = 1; i < 2 * N; i ++) {
        if (reverse(i) == i) pal.push_back(i);
    }

    for (int i = 1; i < M; i ++) f[0][i] = 1;

    for (int i = 1; i < N; i ++) {
        f[i][0] = 0;
        for (int j = 1; j < M; j ++) {
            if (pal[j] <= i) f[i][j] = (f[i][j - 1] + f[i - pal[j]][j]) % MOD;
            else f[i][j] = f[i][j - 1] % MOD;
        }
    }

    int t;
    cin >> t;
    while (t --) {
        int n;
        cin >> n;
        cout << f[n][M - 1] % MOD << endl;
    }
} 
