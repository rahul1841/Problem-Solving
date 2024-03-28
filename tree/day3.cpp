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


Q4: Path to Given Node

bool helper(TreeNode* root, int B, vector<int> &ans){
    if (root == NULL) {
        return false;
    }
    ans.push_back(root->val);

    if (root->val == B) {
        return true;
    }

    if (helper(root->left, B, ans) || helper(root->right, B, ans)) {
        return true;
    }

    ans.pop_back();
    return false;
     
 }
 
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    helper(A,B,ans);
    return ans;
}


Q5: LCA

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        
        if(root->val == p->val || root->val == q->val){
            return root;
        }
        
     TreeNode*   leftAns = lowestCommonAncestor(root->left,p,q);
      TreeNode*  rightAns = lowestCommonAncestor(root->right,p,q);
        
        if(leftAns != NULL && rightAns != NULL){
            return root;
        }
        else if(leftAns){
            return leftAns;
        }
        else if(rightAns){
            return rightAns;
        }
        else{
            return NULL;
        }
    }
};


Q6 : Invert Binary TreeNode

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        invertTree(root->left);
        invertTree(root->right);
        
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        return root;
        
    }
};


Q7: Diameter of Binary Tree

App1:- 
class Solution {
    private:
    int height(TreeNode* root){
        if(root ==  NULL){
            return 0;
        }
        
        int left = height(root->left);
        int right = height(root->right);
        
        int ans = max(left,right) + 1;
        return ans;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        int opt1 = diameterOfBinaryTree(root->left);
        int opt2 = diameterOfBinaryTree(root->right);
        int opt3 = height(root->left) + height(root->right);
        
        int ans = max(opt1,max(opt2,opt3));
        return ans;
    }
};

App2:-
class Solution {
    private:
    int height(TreeNode* root){
        if(root ==  NULL){
            return 0;
        }
        
        int left = height(root->left);
        int right = height(root->right);
        
        int ans = max(left,right) + 1;
        return ans;
    }
public:
    pair<int,int> diameterFast(TreeNode* root){
        if(root == NULL){
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        
        pair<int,int> left = diameterFast(root->left);
        pair<int,int> right = diameterFast(root->right);
        
        int opt1 = left.first;
        int opt2 = right.first;
        int opt3 = left.second + right.second ;
        
        pair<int,int> ans;
        ans.first = max(opt1,max(opt2,opt3));
        ans.second = max(left.second , right.second) + 1;
        
        return ans;
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return diameterFast(root).first;

    }
};