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