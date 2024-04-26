Q1 find-if-path-exists-in-graph

using BFS - 

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        vector<int> adj[n+1];
        vector<int> vis(n, 0); 
        vis[source]=1;
        for (auto e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> q;
        q.push(source);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if (node == destination) return true;
            for(auto it : adj[node]){
                if (!vis[it]){
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        return false;
    }
};

using DFS - 

class Solution {
public:
  bool dfs(int node, vector<int> adj[], vector<int> &vis, int destination){
      vis[node] = 1;
      if(node == destination) return true;
      
      for(auto it : adj[node]){
          if(!vis[it]){
            if (dfs(it, adj, vis, destination))
                return true; // Return true if a valid path is found
        }    
      }
      return false;
  }
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        vector<int> adj[n+1];
        vector<int> vis(n, 0); 
        for (auto e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return  dfs(source, adj, vis, destination );
    }
};


Q3 number-of-provinces

class Solution {
public:
    void dfs(int i,vector<vector<int>>& isConnected,vector<int>&vis){
        vis[i]=1;
        for(int j=0;j<isConnected.size();j++){
            if(isConnected[i][j]==1 && vis[j]==0){
                dfs(j,isConnected,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int>vis(isConnected.size(),0);
        int cnt=0;
        for(int i=0;i<isConnected.size();i++){
            if(vis[i]==0){
                cnt++;
                dfs(i,isConnected,vis);
            }
        }
        return cnt;
    }
};

Q4 detect-cycle-in-a-directed-graph

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        int inorder[V]={0};
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                inorder[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(inorder[i]==0){
                q.push(i);
            }
        }
        int cnt=0;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            cnt++;
            for(auto it:adj[front]){
                inorder[it]--;
                if(inorder[it]==0){
                    q.push(it);
                }
            }
        }
        if(cnt==V) return false;
        return true;
    }
};

Q5 minimum-number-of-vertices-to-reach-all-nodes

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>indeg(n,0);
        vector<int>adj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
        }
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                indeg[it]++;
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};