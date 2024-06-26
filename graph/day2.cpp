Q1 surrounded-regions

class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>& vis,
    vector<vector<char>>& board,int dr[],int dc[],int n,int m){
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            int nrow=row+dr[i];
            int ncol=col+dc[i];

            if((nrow>=0 && nrow<n ) && (ncol>=0 && ncol<m) && board[nrow][ncol]=='O' && !vis[nrow][ncol]){
                dfs(nrow,ncol,vis,board,dr,dc,n,m);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        for(int j=0;j<m;j++){
            if(!vis[0][j] && board[0][j]=='O'){
                dfs(0,j,vis,board,dr,dc,n,m);
            }
            if(!vis[n-1][j] && board[n-1][j]=='O'){
                dfs(n-1,j,vis,board,dr,dc,n,m);
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(i,0,vis,board,dr,dc,n,m);
            }
            if(!vis[i][m-1] && board[i][m-1]=='O'){
                dfs(i,m-1,vis,board,dr,dc,n,m);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};

Q3 rotting-oranges

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        int vis[n][m];
        int cntfresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else{
                    vis[i][j]=0;
                }
                if(grid[i][j]==1) cntfresh++;
            }
        }
        int time=0;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        int cnt=0;
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int t=q.front().second;
            time=max(time,t);
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                if((nrow>=0 && nrow<n)&&(ncol>=0 && ncol<m)&& grid[nrow][ncol]==1 && vis[nrow][ncol]!=2){
                    q.push({{nrow,ncol},time+1});
                    vis[nrow][ncol]=2;
                    cnt++;
                }
            }
        }
        if(cnt!=cntfresh) return -1;
        return time;
    }
};

Q5 number-of-islands

class Solution {
public:
    void bfs(int row,int col, vector<vector<int>>&vis,vector<vector<char>>& grid,int n,int m){
        vis[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                if((nrow>=0 && nrow<n) && (ncol>=0 && ncol<m) && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    bfs(i,j,vis,grid,n,m);
                }
            }
        }
        return cnt;
    }
};

Q6 knight-on-chess-board

int Solution::knight(int A, int B, int C, int D, int E, int F) {
    vector<vector<int>>vis(A+1,vector<int>(B+1,0));
    queue<pair<pair<int,int>,int>>q;
    q.push({{C,D},0});
    vis[C][D]=1;
    int delr[8]={-2,-1,1,2,2,1,-1,-2};
    int delc[8]={1,2,2,1,-1,-2,-2,-1};
    while(!q.empty()){
        int row=q.front().first.first;
        int col=q.front().first.second;
        int dis=q.front().second;
        q.pop();
        if(row==E && col==F){
            return dis;
        }
        for(int i=0;i<8;i++){
            int nrow=row+delr[i];
            int ncol=col+delc[i];
            if((nrow>=1 && nrow<=A) && (ncol>=1 && ncol<=B) && vis[nrow][ncol]==0){
                q.push({{nrow,ncol},dis+1});
                vis[nrow][ncol]=1;
            }
        } 
    }
    
    
    return -1;
}


Q7 distance-of-nearest-cell-having-1

class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n=grid.size();
	    int m=grid[0].size();
	    vector<vector<int>>vis(n,vector<int>(m,0));
	    vector<vector<int>>dist(n,vector<int>(m,0));
	    queue<pair<pair<int,int>,int>>q;
	    //q({{row,col},dis})
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==1){
	                q.push({{i,j},0});
	                vis[i][j]=1;
	            }
	            else{
	                vis[i][j]=0;
	            }
	        }
	    }
	    int delr[4]={-1,0,1,0};
	    int delc[4]={0,1,0,-1};
	    while(!q.empty()){
	        int row=q.front().first.first;
	        int col=q.front().first.second;
	        int dis=q.front().second;
	        q.pop();
	        dist[row][col]=dis;
	        vis[row][col]=1;
	        for(int i=0;i<4;i++){
	            int nrow=row+delr[i];
	            int ncol=col+delc[i];
	            if((nrow>=0 && nrow<n) && (ncol>=0 && ncol<m) && vis[nrow][ncol]==0 ){
	                q.push({{nrow,ncol},dis+1});
	                vis[nrow][ncol]=1;
	            }
	        }
	    }
	    return dist;
	}
};
