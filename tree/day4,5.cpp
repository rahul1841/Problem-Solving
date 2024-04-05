Q1: Check if each internal node of a BST has exactly one child

#include <bits/stdc++.h>
using namespace std;
bool hasOnlyOneChild(int pre[], int size) {
  int nextDif, lastDif;
  for (int i = 0; i < size - 1; i++)
  {
    nextDif = pre[i] - pre[i + 1];
    lastDif = pre[i] - pre[size - 1];
    if (nextDif * lastDif < 0)
      return false;
  }
  return true;
}

Q2: Convert sorted array to BST

class Solution {
public:
    TreeNode* constbst(vector<int>& nums,int s,int e){
        if(s > e){
            return NULL;
        }
        int mid=(s+e)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=constbst(nums,s,mid-1);
        root->right=constbst(nums,mid+1,e);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        if(n == 0){
            return NULL;
        }
        int s=0;
        int e=n-1;
        return constbst(nums,s,e);
    }
};

Q3: Validate binary TreeNode

class Solution {
public:
   bool solve(TreeNode* root, long min, long max) {
        if (root == NULL)
            return true;

        if (root->val <= min || root->val >= max)
            return false;

        return solve(root->left, min, root->val) &&
               solve(root->right, root->val, max);
    }
    bool isValidBST(TreeNode* root) {
        return solve(root, LONG_MIN , LONG_MAX);
    }
};

Q4: Largest bst

class Solution{
    public:
    /*You are required to complete this method */
    bool isvalidate(Node *root, int min, int max){
        if (root == NULL){
            return true;
        }  
        if (min >= root->data || root->data >= max){
            return false;
        }
        return isvalidate(root->left, min, root->data) && isvalidate(root->right, root->data, max);
    }
    int count(Node *root){
        if (root == NULL){
            return 0;
        }  
        return 1+count(root->left)+count(root->right);
    }
    int largestBst(Node *root) {
        if (root == NULL){
            return 0;
        }  
        if(isvalidate(root, INT_MIN, INT_MAX)){
            return count(root);
        } 
        int leftAns=largestBst(root->left);
        int rightAns=largestBst(root->right);
        return max(leftAns, rightAns);
    }
};

Q5: Find common nodes in 2 BST

class Solution
{
    public:
    map<int,bool>mp;
    void getnodes(Node*root1){
        if(root1==NULL){
            return;
        }
        getnodes(root1->left);
        mp[root1->data]=true;
        getnodes(root1->right);
    }
    
    //function to get answer
    void getans(Node*root2,vector<int>& ans){
        if(root2==NULL){
            return;
        }
        //inorder
        getans(root2->left,ans);
        if(mp[root2->data]==true){
            ans.push_back(root2->data);
        }
        getans(root2->right,ans);
    }
     
    vector <int> findCommon(Node *root1, Node *root2)
    {
     //Your code here
     vector<int>ans;
     getnodes(root1);
     getans(root2,ans);
     return ans;
    }
};

Q6: Range sum of BST

class Solution {
public:
    int sum;
    void preorder(TreeNode* root, int l, int h){
        if(root==NULL){
            return;
        }
        if(root->val>=l && root->val<=h){
            sum+=root->val;
        }
        preorder(root->left,l,h);
        preorder(root->right,l,h);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        sum=0;
        preorder(root,low,high);
        return sum;
    }
};

Q7: Implementing ceil in BST

int findCeil(Node* root, int input) {
 int res=-1;
 while(root!=NULL){
     if(root->data==input)
     return root->data;
     if(root->data<input)
     root=root->right;
     else{
         if(res==-1) res=root->data;
         else if(root->data-input<res-input)
         res=root->data;
        root= root->left;
     }
 }
 return res;
}