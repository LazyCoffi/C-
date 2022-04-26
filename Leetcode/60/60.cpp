#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:

    string getPermutation(int n, int k) {
        vector<int> func;
        vector<int> vaild;
        string ans = "";
        func.push_back(1);
        k --;

        for (int i = 1; i <= n + 1; i ++) {
            func.push_back(func[i - 1] * i);
            vaild.push_back(1);
        }

        for (int i = 1; i <= n; i ++) {
            int res = k / func[n - i] + 1;
            for (int j = 1; j <= n; j ++) {
                res -= vaild[j];
                if (res == 0) {
                    ans += '0' + j;    
                    vaild[j] = 0;
                    break;
                }
            }
            k %= func[n - i];
        }       

        return ans;
    }
};

int main() {
    Solution *sol = new Solution();
    cout << sol->getPermutation(4, 9) << endl;
}
