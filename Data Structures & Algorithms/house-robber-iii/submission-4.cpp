/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    unordered_map<TreeNode*, vector<int>> dp;

    int solver(TreeNode* root, bool can){

        if(!root) return 0;

        if(dp[root].size() && dp[root][can] != -1)
            return dp[root][can];

        int pick = 0;

        if(can){
            pick = root->val +
                   solver(root->left, false) +
                   solver(root->right, false);
        }

        int notPick =
            solver(root->left, true) +
            solver(root->right, true);

        return dp[root][can] = max(pick, notPick);
    }

    int rob(TreeNode* root) {

        function<void(TreeNode*)> init = [&](TreeNode* node){

            if(!node) return;

            dp[node] = vector<int>(2, -1);

            init(node->left);
            init(node->right);
        };

        init(root);

        return solver(root, true);
    }
};