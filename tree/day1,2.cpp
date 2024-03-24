Q1: Maximum Depth of Binary Tree

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


Q4: level order traversel

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map< int, vector<int> > > nodes;
        queue< pair<TreeNode*, pair<int, int> > > q;
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }
        
        q.push(make_pair(root, make_pair(0, 0)));
        
        while(!q.empty()){
            pair<TreeNode*, pair<int, int> > temp = q.front();
            q.pop();
            TreeNode* frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;
            
            nodes[hd][lvl].push_back(frontNode->val);
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left, make_pair(hd-1, lvl+1)));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right, make_pair(hd+1, lvl+1)));
            }
        }
        for(auto i : nodes){
            vector<int> temp;
            for(auto j : i.second){
                sort(j.second.begin(), j.second.end());
                for(auto k : j.second){
                    temp.push_back(k);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};


Q5: same Tree

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL){
            return true;
        }
        if(p == NULL && q != NULL){
            return false;
        }
        if(p != NULL && q == NULL){
            return false;
        }
        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);
        bool data = (p->val == q->val);
        
        if(left && right && data){
            return true;
        }
        return false;
    }
};


Q6: Height of Binary Tree

void height(TreeNode<int> *root, int &maxh, int currh){
    if(root == NULL){
        maxh = max(maxh, currh);
        return;
    }
    height(root->left, maxh, currh+1);
    height(root->right, maxh, currh+1);

}
int heightOfBinaryTree(TreeNode<int> *root)
{
	// Write your code here.
    int maxh = 0;
    height(root, maxh, 0);
    return maxh;
}


Q7: Top view of Binary Tree

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        map<int, int> mp;
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        queue<pair<Node*, int> > q;
        q.push(make_pair(root, 0));
        
        while(!q.empty()){
            pair<Node*, int> node = q.front();
            Node* frontNode = node.first;
            int hd = node.second;
            
            q.pop();
            
            if(mp.find(hd) == mp.end()){
                mp[hd] = frontNode->data;
            }
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left, hd-1));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right, hd+1));
            }
        }
        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};


Q8: Find Bottom Left Tree Value

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode* > q;
        q.push(root);

        TreeNode* node;
        while(!q.empty()){
            node = q.front();
            q.pop();
            if(node->right){
                q.push(node->right);
            }
            if(node->left){
                q.push(node->left);
            }
        }
        return  node->val;
    }
};


Q9: Find Bottom left tree Value

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode* > q;
        q.push(root);

        TreeNode* node;
        while(!q.empty()){
            node = q.front();
            q.pop();
            if(node->right){
                q.push(node->right);
            }
            if(node->left){
                q.push(node->left);
            }
        }
        return  node->val;
    }
};


Q10: Serialize and Deserialize Binary Tree

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL){
            return "";
        }
        string str;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node == NULL) {
                str.append("#,");
            }else{
                str.append(to_string(node->val)+",");
            }
            if(node != NULL){
                q.push(node->left);
                q.push(node->right);
            }
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            getline(s,str,',');
            if(str == "#"){
                node->left = NULL;
            }
            else{
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }
            getline(s,str,',');
            if(str == "#"){
                node->right = NULL;
            }
            else{
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};