Q1 find-if-path-exists-in-graph

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>>mp;
        for(auto it:edges){
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }
        vector<bool>vis(n,0);
        vis[source]=1;
        queue<int>q;
        q.push(source);
        while(!q.empty()){
            int front=q.front();
            q.pop();
            if(front==destination){
                return true;
            }
            for(auto it:mp[front]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        return false;

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