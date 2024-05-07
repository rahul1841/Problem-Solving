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