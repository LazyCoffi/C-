#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> up(n + 1, vector<int>(m + 1, 0));
        int ans = 0;

        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (matrix[i][j] == '0') continue;
                up[i][j] = 1;
                if (i != 0) up[i][j] += up[i - 1][j];
            }

            stack<pair<int, int>> stk;
            vector<int> left(m + 1, 0);
            vector<int> right(m + 1, 0);

            for (int j = 0; j < m; j ++) {
                while (!stk.empty() && stk.top().first >= up[i][j]) stk.pop();
                if (!stk.empty()) left[j] = stk.top().second + 1;
                else left[j] = 0;
                stk.push(make_pair(up[i][j], j));
            }
            while (!stk.empty()) stk.pop();

            for (int j = m - 1; j >= 0; j --) {
                while (!stk.empty() && stk.top().first >= up[i][j]) stk.pop();
                if (!stk.empty()) right[j] = stk.top().second - 1;
                else right[j] = m - 1;
                stk.push(make_pair(up[i][j], j));
            }
            while (!stk.empty()) stk.pop();

            for (int j = 0; j < m; j ++) {
                ans = max(ans, up[i][j] * (right[j] - left[j] + 1));
            }
        }

        return ans;
    }
};

int main() {
    
}
