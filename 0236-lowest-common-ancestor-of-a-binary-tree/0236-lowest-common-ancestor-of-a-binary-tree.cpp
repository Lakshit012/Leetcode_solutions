class Solution {
public:
    bool getPath(TreeNode*root,TreeNode*target,vector<TreeNode*>&path){
        if(root==NULL) return false;
        path.push_back(root);
        if(root==target) return true;
        if(getPath(root->left,target,path) || getPath(root->right,target,path)) return true;
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;
        getPath(root,p,path1);
        getPath(root,q,path2);

        TreeNode*ans=NULL;
        int i=0;
        while(i<path1.size() &&  i<path2.size()){
            if(path1[i]==path2[i]){
                ans=path1[i];
            }
            else{
                break;
            }
            i++;
        }
        return ans;
    }
};
