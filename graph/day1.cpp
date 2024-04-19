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