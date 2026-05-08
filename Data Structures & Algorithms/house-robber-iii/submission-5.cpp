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

    unordered_map<TreeNode*, int> idxMap;

    vector<vector<int>> dp;

    int idx = 0;

    void assignIndex(TreeNode* root){

        if(!root) return;

        idxMap[root] = idx++;

        assignIndex(root->left);
        assignIndex(root->right);
    }

    int solve(TreeNode* root, bool can){

        if(!root) return 0;

        int id = idxMap[root];

        // Memoization
        if(dp[id][can] != -1)
            return dp[id][can];

        int pick = 0;

        // Rob current node
        if(can){

            pick =
                root->val +
                solve(root->left, false) +
                solve(root->right, false);
        }

        // Skip current node
        int notPick =
            solve(root->left, true) +
            solve(root->right, true);

        return dp[id][can] =
            max(pick, notPick);
    }

    int rob(TreeNode* root) {

        assignIndex(root);

        dp.resize(idx, vector<int>(2, -1));

        return solve(root, true);
    }
};