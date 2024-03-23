Q: Maximum Depth of Binary Tree

using normal recursion: 

class Solution {
public:
    int maxDepth(TreeNode* root) {
        //base case
        if(root == NULL){
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        
        int ans = max(left,right) + 1;
        return ans;
    }
};

using inorder traversel:

class Solution {
private:
void inorder(TreeNode* root, int &maxi, int dep){
    if(root == nullptr){
        maxi = max(maxi, dep);
        return;
    }
    inorder(root->left, maxi, dep+1);
    inorder(root->right, maxi, dep+1);
}

public:
    int maxDepth(TreeNode* root) {
        int maxDepth = 0;
        inorder(root, maxDepth, 0);
        return maxDepth;
    }
};


Q2: level order traversel

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            vector<int> v;
            for(int i = 0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                v.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};


Q3: Odd even level difference

class Solution{
  public:
    /*You are required to complete this function*/
    int getLevelDiff(Node *root)
    {
     if(root == NULL){
          return 0;
      }
      int oddSum = 0;
      int evenSum = 0;
      bool flag = true;

      queue<Node* > q;
      q.push(root);
      
      while(!q.empty()){
         int size=q.size();
            
          for(int i=0;i<size;i++){
          Node* node = q.front();
          q.pop();
          if(flag){
              oddSum += node->data;
          }else{
              evenSum += node->data;
          }
          if(node->left){
              q.push(node->left);
          }
          if(node->right){
              q.push(node->right);
          }
          }
          flag = !flag;
      }
      return oddSum-evenSum;
    }
};