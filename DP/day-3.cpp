Q1 coin-change

class Solution {
public:
    int coinChange(vector<int>& coins, int w) {
        int n=coins.size();
        int dp[n+1][w+1];
        for(int i=0;i<w+1;i++) dp[0][i]=INT_MAX-1;
        for(int i=0;i<n+1;i++) dp[i][0]=0;
        dp[0][0]=0;
        for(int i=1,j=1;j<w+1;j++){
            if(j%coins[0]==0){
                dp[i][j]=j/coins[0];
            }
            else{
                dp[i][j]=INT_MAX-1;
            }
        }
        for(int i=2;i<n+1;i++){
            for(int j=1;j<w+1;j++){
                if(coins[i-1]<=j){
                    dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        if (dp[n][w]==2147483646) return -1;
        return dp[n][w];
    }
};

Q2 coin-change-ii

class Solution {
public:
    int solve(int i,int amt,vector<int>& coins,vector<vector<int>>& dp){
        if(i==0){
             return (amt%coins[0]==0);
        }
        if(amt==0)return 1;
        if(dp[i][amt]!=-1)return dp[i][amt];
        int nott=solve(i-1,amt,coins,dp);
        int take=0;
        if(coins[i]<=amt){
            take=solve(i,amt-coins[i],coins,dp);
        
        }
        return dp[i][amt]=nott+take;
    }
    int change(int amount, vector<int>& coins) {
        int n= coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans= solve(n-1,amount,coins,dp);   
         return ans;
    }
};

Q3 maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        dp[0] = nums[0];
        int maximumSumSubarray = nums[0];
        for(int i=1; i<n; i++){
            dp[i] = nums[i] + (dp[i-1] > 0 ? dp[i-1] : 0);
            maximumSumSubarray = max(maximumSumSubarray, dp[i]);
        }
        return maximumSumSubarray;
    }
};

Q4 maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n , vector<int>( 2, nums[0]));
        int ans=nums[0];
        for(int i=1;i<n;i++){
            dp[i][0]=max(dp[i-1][0]*nums[i]  , max( dp[i-1][1]*nums[i]  , nums[i] ));
            dp[i][1]=min( dp[i-1][0]*nums[i] , min( dp[i-1][1]*nums[i] , nums[i] ));
            ans = max(ans , max(dp[i][1] , dp[i][0]));
        }
        return ans; 

    }
};

Q5 longest-increasing-subsequence

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();
        
        vector<int> next(n+1, 0);

        for(int i = n-1 ; i >= 0; i--){

            vector<int> curr(n+1,0);

            for(int j = i; j >= 0; j--){

                int p = 0;
                int nP = next[j];
                if(j==0 || nums[i] > nums[j-1]){
                    p = 1 + next[i+1];
                }
                curr[j] = max(p, nP);
            }
            next = curr;
        }
        return next[0];
    }
};


Q6 cses.fi/problemset/task/1633

Q7 cses.fi/problemset/task/1634

Q8 cses.fi/problemset/task/1636