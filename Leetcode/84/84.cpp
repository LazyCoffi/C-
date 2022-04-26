#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
    struct Node {
        int h, p;
    };

public:
    int largestRectangleArea(vector<int>& heights) {
        stack<Node> stk;
        int ans = 0;
        int len = heights.size();
        vector<int> left(len + 1), right(len + 1);

        for (int i = 0; i < len; i ++) {
            while (!stk.empty() && stk.top().h >= heights[i]) stk.pop();
            if (!stk.empty()) left[i] = stk.top().p + 1;
            else left[i] = 0;
            stk.push((Node){heights[i], i});
        }
        while (!stk.empty()) stk.pop();

        for (int i = len - 1; i >= 0; i --) {
            while (!stk.empty() && stk.top().h >= heights[i]) stk.pop();
            if (!stk.empty()) right[i] = stk.top().p - 1;
            else right[i] = len - 1;
            stk.push((Node){heights[i], i});
        }
        while (!stk.empty()) stk.pop();

        for (int i = 0; i < len; i ++) {
            ans = max(ans, heights[i] * (right[i] - left[i] + 1));
        }

        return ans;
    }
};

int main() {
    Solution *sol = new Solution();
    vector<int> nums = {2, 1, 2};
    cout << sol->largestRectangleArea(nums) << endl;
}
