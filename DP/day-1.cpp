Q1 CLimbing-Stairs

class Solution {
public:
    int climbStairs(int n) {
        if(n==0 || n==1){
            return 1;
        }
        vector<int>dp(n+1);
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};

Q2 jump-game-ii

class Solution {
public:
    int solve(vector<int>&arr,int ind,vector<int>&dp){
        if(ind>=arr.size()-1)return 0;
        if(dp[ind]!=10001)return dp[ind];
        for(int i=1;i<=arr[ind];i++){
            dp[ind]=min(dp[ind],1+solve(arr,i+ind,dp));
        }
        return dp[ind];
    }
    int jump(vector<int>& arr) {
        int n=arr.size();
        vector<int>dp(n+1,10001);
        return solve(arr,0,dp);
    }
};

Q3 perfect-squares

class Solution {
public:
    int numSquares(int n) {
        int i = 0;
        vector<int> squares;
        while (i * i <= n){
            squares.push_back(i * i);
            i += 1;
        }
        vector<int> dp(n + 1, 10000);
        dp[0] = 0;
        for (i = 1; i <= n; ++i){
            for (int j = 0; j < squares.size(); ++j){
                if (i - squares[j] >= 0){
                    dp[i] = min(dp[i], dp[i - squares[j]] + 1);
                }
            }
        }
        return dp[n];
    }
};