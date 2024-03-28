Q1: left view binary tree

void solve(BinaryTreeNode<int>* root,vector<int> &ans, int lvl){
    if(root == NULL) return;
    if(ans.size() < lvl){
        ans.push_back(root->data);
    }
    solve(root->left, ans, lvl+1);
    solve(root->right, ans, lvl+1);
}

vector<int> printLeftView(BinaryTreeNode<int>* root) {
    // Write your code here.
    vector<int> ans;
    solve(root, ans, 1);
    return ans;
}


Q2: Binary tree right side view 

class Solution {
public:
    void solve(TreeNode* root, vector<int> &ans, int lvl){
        if(root == NULL){
            return;
        }
        if(ans.size() < lvl){
            ans.push_back(root->val);
        }
        solve(root->right,ans,lvl+1);
        solve(root->left,ans,lvl+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solve(root, ans, 1);
        return ans;
    }
};


Q3: Binary tree paths

class Solution {
public:
    void solve(TreeNode* root, vector<string> &ans, string curr){
        if(root->left == NULL && root->right == NULL ){
            curr += to_string(root->val);
            ans.push_back(curr);
            curr.pop_back();
            return;
        }
        curr += to_string(root->val)+"->";
        if(root->left){
        solve(root->left,ans, curr);
        }
        if(root->right){
        solve(root->right,ans, curr);
        }
         curr.pop_back();
        curr.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string curr;
        solve(root, ans, curr);
        return ans;
    }
};
