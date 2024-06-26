Q1 minimum-edges

class Solution{
    public:
        int minimumEdgeReversal(vector<vector<int>> &edges,int n,int src,int dst)
        {
            vector<pair<int,int>>adj[n+1];
            for(int i=0;i<edges.size();i++){
                adj[edges[i][0]].push_back({edges[i][1],0});
                adj[edges[i][1]].push_back({edges[i][0],1});
            }
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
            vector<int>dist(n+1,1e9);
            dist[src]=0;
            pq.push({0,src});
            while(!pq.empty()){
                int dis=pq.top().first;
                int node=pq.top().second;
                pq.pop();
                for(auto it:adj[node]){
                    int edgewt=it.second;
                    int adjnode=it.first;
                    if(dis+edgewt<dist[adjnode]){
                        dist[adjnode]=dis+edgewt;
                        pq.push({dist[adjnode],adjnode});
                    }
                }
            }
            if(dist[dst]==1e9){
                return -1;
            }
            else{
                return dist[dst];
            }
        }
};

Q2 course-schedule

    class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        for(auto it : prerequisites){
            adj[it[0]].push_back(it[1]);
        }
        vector<int>indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(topo.size()==numCourses){
            return true;
        }
        return false;
    }
};

Q3 course-schedule-ii

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        for(auto it : prerequisites){
            adj[it[0]].push_back(it[1]);
        }
        vector<int>indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(topo.size()==numCourses){
            reverse(topo.begin(),topo.end());
            return topo;
        }
        return {};
    }
};

Q4 all-ancestors-of-a-node-in-a-directed-acyclic-graph

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
        }
        vector<vector<int>>ans(n);
        for(int node=0;node<n;node++){
            vector<int>vis(n,0);
            queue<int>q;
            q.push(node);
            vis[node]=1;
            while(!q.empty()){
                int currnode=q.front();
                q.pop();
                for(auto it:adj[currnode]){
                    if(!vis[it]){
                        vis[it]=1;
                        q.push(it);
                        ans[it].push_back(node);
                    }
                }
            }
        }
        return ans;
    }
};

Q6 detect-cycle-in-a-directed-graph

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int i,int vis[],int pathvis[],vector<int>adj[]){
        vis[i]=1;
        pathvis[i]=1;
        for(auto it: adj[i]){
            if(!vis[it]){
                if(dfs(it,vis,pathvis,adj)==true) return true;
            }
            else if(pathvis[it]){
                return true;
            }
        }
        pathvis[i]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V]={0};
        int pathvis[V]={0};
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,vis,pathvis,adj)==true) return true;
            }
        }
        return false;
    }
};