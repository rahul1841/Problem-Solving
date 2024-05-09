Q1 minimum-time-to-visit-disappearing-nodes

class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        unordered_map<int, vector<pair<int,int>>> adj;
        for(auto &vec: edges){
            int u= vec[0];
            int v= vec[1];
            int w= vec[2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> ans(n, -1);
        vector<bool> visited(n, false);
        pq.push({0, 0});
        ans[0]= 0;
        while(!pq.empty()){
            auto topPair= pq.top();
            pq.pop();
            
            int currWt= topPair.first;
            int currNode= topPair.second;
            if (visited[currNode]) continue;
            visited[currNode] = true;
            for(auto &nbr: adj[currNode]){
                int newWt = currWt + nbr.second;
                if (newWt < disappear[nbr.first] && (ans[nbr.first] == -1 || newWt < ans[nbr.first])) {
                    pq.push({newWt, nbr.first});
                    ans[nbr.first]= newWt;
                }
            }
        }
        
        return ans;
    }
};

Q2 path-with-maximum-probability

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<double,int>>adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({succProb[i],edges[i][1]});
            adj[edges[i][1]].push_back({succProb[i],edges[i][0]});
        }
        vector<double>dist(n,DBL_MIN);
        vector<bool>vis(n,false);
        dist[start_node]=1.0;
        priority_queue<pair<double,int>>pq;
        pq.push({1.0,start_node});
        while(!pq.empty()){
            int node=pq.top().second;
            pq.pop();
            if(!vis[node]){
                vis[node]=true;
                for(auto it:adj[node]){
                    int adjnode=it.second;
                    double adjwt=it.first;
                    if(dist[adjnode]<dist[node]*adjwt){
                        dist[adjnode]=dist[node]*adjwt;
                        pq.push({dist[adjnode],adjnode});
                    }
                }
            }
        }
        return dist[end_node];
    }
};

Q3 network-delay-time

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});

        vector<pair<int,int>>adj[n+1];
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int wt=it.second;
                int adjnode=it.first;
                if(dist[adjnode]>dis+wt){
                    dist[adjnode]=dis+wt;
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }
        int mx=*max_element(dist.begin()+1,dist.end());
        return mx==INT_MAX?-1:mx;
    }
};

Q4 path-with-minimum-effort

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> > pq;
        pq.push({0,{0,0}});
        //{dis,{row,col}}
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));

        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        while(!pq.empty()){
            int dis=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            if(row==n-1 && col==m-1) return dis;
            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int newdis=max(dis,abs(grid[nrow][ncol]-grid[row][col]));
                    if(newdis<dist[nrow][ncol]){
                        dist[nrow][ncol]=newdis;
                        pq.push({newdis,{nrow,ncol}});
                    }
                }
            }
        }
        return 0;
    }
};