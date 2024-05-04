Q1 strongly-connected-components-kosarajus-algo

class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int i,vector<int>& vis,stack<int>&st, vector<vector<int>>& adj){
	    vis[i]=1;
	    for(auto it:adj[i]){
	        if(vis[it]==0){
	            dfs(it,vis,st,adj);
	        }
	    }
	    st.push(i);
	}
	void dfs2(int i,vector<int>& vis, vector<vector<int>>&adjt){
	    vis[i]=1;
	    for(auto it:adjt[i]){
	        if(vis[it]==0){
	            dfs2(it,vis,adjt);
	        }
	    }
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
       vector<int>vis(V,0);
       stack<int>st;
       for(int i=0;i<V;i++){
           if(vis[i]==0){
              dfs(i,vis,st,adj);
           }
       }
       
       vector<vector<int>>adjt(V);
       for(int i=0;i<V;i++){
           vis[i]=0;
           for(auto it :adj[i]){
               adjt[it].push_back(i);
           }
       }
       int scc=0;
       while(!st.empty()){
           int node=st.top();
           st.pop();
           if(vis[node]==0){
               scc++;
               dfs2(node,vis,adjt);
           }
       }
       return scc;
    }
};

Q2 is-graph-bipartite

class Solution {
public:
    bool bfs(int node,vector<int>& color,vector<vector<int>>&graph){
        queue<int>q;
        q.push(node);
        color[node]=0;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            for(auto it : graph[front]){
                if(color[it]==-1){
                    color[it]=!color[front];
                    q.push(it);
                }
                else if(color[it]==color[front]){
                    return false;
                }
            }   
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(color[i]==-1){
                if(bfs(i,color,graph)==false) return false;
            }
        }
        return true;
    }
};

Q4 shortest-cycle-in-a-graph

class Solution {
public:
    int ans=INT_MAX;
    void bfs(int i,vector<int>adj[],vector<int>&vis,vector<int>&dis){
        queue<pair<int,int>>q;
        q.push({i,-1});
        vis[i]=1;
        dis[i]=0;
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto it:adj[node]){
                if(vis[it]==0){
                    dis[it]=dis[node]+1;
                    q.push({it,node});
                    vis[it]=1;
                }
                else if(it !=parent){
                    ans=min(ans,dis[it]+dis[node]+1);
                }
            }
        }
    }
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<int>adj[n+1];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++){
            vector<int>vis(n+1,0);
            vector<int>dis(n+1,INT_MAX);
            bfs(i,adj,vis,dis);
        }
        if(ans==INT_MAX){
            return -1;
        }
        else {
            return ans;
        }
    }
};