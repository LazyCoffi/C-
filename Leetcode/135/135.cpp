#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int ans = 0;

        int len = ratings.size();
        vector<int> range(len + 1, 0);
        for (int i = 0; i < len; i ++) {
            if (i > 0 && ratings[i - 1] < ratings[i]) range[i] = range[i - 1] + 1;
            else range[i] = 1;
        }

        int res = 0;
        for (int i = len - 1; i >= 0; i --) {
            if (i < len - 1 && ratings[i] > ratings[i + 1]) res ++;
            else res = 1;
            ans += max(range[i], res);
        }
        
        return ans;
    }
};

int main() {
    Solution *sol = new Solution();
    vector<int> vec = {1, 3, 2, 2, 1};
    cout << sol->candy(vec) << endl;
}
