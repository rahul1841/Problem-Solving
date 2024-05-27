Q1 length-of-the-longest-subsequence-that-sums-to-target

class Solution {
public:
     int dp[1005][1005];
    int fun(vector<int> &arr,int t,int i)
    {
        if(t==0) return 0;
        if(i>=arr.size()) return -1*1e5;
        
        if(dp[i][t]!=-1) return dp[i][t];
        
        if(t>=arr[i])
        return dp[i][t] = max(1+fun(arr,t-arr[i],i+1),fun(arr,t,i+1));
        
        return dp[i][t] = fun(arr,t,i+1);
    }
    int lengthOfLongestSubsequence(vector<int>& arr, int t) {
        
        memset(dp,-1,sizeof(dp));
        int ans = fun(arr,t,0);
        return ans<0 ? -1 :ans;    
    }
};

Q2 number-of-longest-increasing-subsequence

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int n=nums.size();

        vector<pair<int,int>> dp(n,{1,1});

        int maxi=0,cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){

                if(nums[i]>nums[j]){
                    if(dp[i].first==dp[j].first+1){
                        dp[i].second+=dp[j].second;
                    }
                    else if(dp[i].first<dp[j].first+1){
                        dp[i].second=dp[j].second;
                        dp[i].first=dp[j].first+1;
                    }
                }
            }

            if(dp[i].first==maxi) cnt+=dp[i].second;

            else if(dp[i].first>maxi){
                maxi=dp[i].first;
                cnt=dp[i].second;
            }
        }

        return cnt;
    }
};

Q3 unique-paths

class Solution {
public:
    int f(int i,int j,vector<vector<int>>&dp){
        if(i==0 && j==0){
            return 1;
        }
        if(i<0 || j<0) {
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int up=f(i-1,j,dp);
        int left=f(i,j-1,dp);
        return dp[i][j]=up+left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return f(m-1,n-1,dp);
    }
};

Q4 unique-paths-ii

class Solution {
public:
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1||obstacleGrid[n-1][m-1]==1)return 0;
        int dp[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(obstacleGrid[i][j]==1) dp[i][j]=0;
                else if(i==0 && j==0 )  dp[i][j]=1;
                else{
                    int up=0;
                    int left=0;
                    if(i>0) up=dp[i-1][j];
                    if(j>0) left=dp[i][j-1];
                    dp[i][j]=up+left;
                }
            }
        }
        return dp[n-1][m-1];
    }
};

Q5 minimum-path-cost-in-a-grid

class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int j, vector<vector<int>>&grid, int m, int n, vector<vector<int>>& moveCost) {
        if (i == m - 1) return grid[i][j];

        if (i >= m || j >= n) return 1e9;

        if (dp[i][j] != -1) return dp[i][j];

        int res = 1e9;

        for (int k = 0; k < n; k++) {
            res = min(res, grid[i][j] + moveCost[grid[i][j]][k] + solve(i + 1, k, grid, m, n, moveCost));
        }

        return dp[i][j] = res;
    }


    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size();
        int n = grid[0].size();

        dp = vector<vector<int>>(m, vector<int>(n, -1));
        int res = 1e9;

        for (int j = 0; j < n; j++) {
            res = min(res, solve(0, j, grid, m, n, moveCost));
        }

        return res;
    }
};

Q6 minimum-path-sum

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
       int m=grid.size();
       int n=grid[0].size();

       vector<vector<int>> output(m, vector<int>(n,grid[m-1][n-1]));
       

       for(int i=n-2 ;i>=0;i--){
           output[m-1][i]=output[m-1][i+1]+grid[m-1][i];
       }
       for(int i=m-2; i>=0;i--){
           output[i][n-1]=output[i+1][n-1]+grid[i][n-1];
       }

       for(int i=m-2 ;i>=0;i--){
           for(int j=n-2 ;j>=0;j--){
               output[i][j]=min(output[i+1][j], output[i][j+1]) +grid[i][j];
           }
       }
       return output[0][0];
    }
};