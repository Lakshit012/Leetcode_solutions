class Solution {
public:
    void solve(TreeNode*root,vector<int>&ans){
        if(root==NULL)return;
        if(root->left==NULL && root->right==NULL) ans.push_back(root->val);
        solve(root->left,ans);
        solve(root->right,ans);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>ans1;
        vector<int>ans2;
        solve(root1,ans1);
        solve(root2,ans2);
        return ans1==ans2;
    }
};