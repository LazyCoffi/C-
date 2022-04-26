#include <iostream>
#include <cstdio>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    int ans = -1e9;

    int dfs(TreeNode* u) {
        int val = u->val;
        int l = (u->left == nullptr ? 0 : dfs(u->left));
        int r = (u->right == nullptr ? 0 : dfs(u->right));
        ans = max(ans, max(val, max(val + l, max(val + r, val + l + r))));
        return max(val, max(val + l, val + r));
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);        
        return ans;
    }
};

int main() {

}
