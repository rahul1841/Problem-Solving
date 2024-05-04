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