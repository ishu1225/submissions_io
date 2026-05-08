/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    unordered_map<int,int> mp;
    int preInd=0;
    TreeNode* solve(vector<int> &in,vector<int>&pre, int start, int end){
        if(start>end)return NULL;
        int rootVal=pre[preInd++];
        TreeNode* root=new TreeNode(rootVal);
        int pos=mp[rootVal];
        root->left=solve(in,pre,start,pos-1);
        root->right=solve(in,pre,pos+1,end);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        for(int i=0;i<=in.size()-1;i++){
            mp[in[i]]=i;
        }
        return solve(in,pre,0,in.size()-1);
    }
};
