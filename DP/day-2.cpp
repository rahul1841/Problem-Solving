Q1 friends-pairing-problem5425

class Solution
{
    public:
    
    int mod=1000000007;
    
    long long solve(int i,vector<long long>& dp)
    {
        if(i==1 or i==2)
        return i;
        if(dp[i]!=-1)
        return dp[i];
        long long a=solve(i-1,dp)%mod;
        long long b=((i-1)*(solve(i-2,dp)%mod))%mod;
        
        return dp[i]=(a+b)%mod;
    }
    int countFriendsPairings(int n) 
    { 
        vector<long long> dp(n+1,-1); 
        return solve(n,dp);
    }
};      

Q2 number-of-dice-rolls-with-target-sum

class Solution {
public:
int mod=1e9+7;
int solve(int k, int n, int target,  vector<vector<int>>&dp){
    if(target==0 and n==0)
        return 1;
    if(n==0 or target<=0)
        return 0;
    int ans=0;
    if( dp[n][target]!=-1)
        return dp[n][target];
    for(int i=1;i<=k;i++)
        ans=(ans+ solve(k, n-1, target-i, dp))%mod;
    return dp[n][target]=ans%mod;
}
    
int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1, vector<int>(target+1, -1));
        return solve(k, n, target, dp);
    }
};

Q3 decode-ways

class Solution {
public:
int getWays(int idx, int n, string& s, vector<int>& dp) {
    if(idx >= n) return 1;
    if(s[idx] == '0') return 0;

    if(dp[idx] != -1) {
        return dp[idx];
    }
        
    int oneDigit = getWays(idx + 1, n, s, dp);
    int twoDigit = 0;
    if(idx + 1 < n) {
        int first = s[idx] - '0';
        int second = s[idx + 1] - '0';
        int combo = first * 10 + second;
        if(combo <= 26) {
            twoDigit = getWays(idx + 2, n, s, dp);
        }
    }
    return dp[idx] = oneDigit + twoDigit;
}

int numDecodings(string s) {
    int n = s.size();
    vector<int> dp(n, -1);
    return getWays(0, n, s, dp);
    }
};

Q4 decode-ways-ii

class Solution {
public:
    long solve(string& s,int i,int n,vector<long>& dp){
        long mod=1e9+7;
        if(dp[i]!=-1)return dp[i];
        if(i==n || s[i]=='0')return dp[i]=0;
        if(i==n-1){
            if(s[i]=='*')
                return dp[i]=9;
            return dp[i]=1;
        }
        long ans=0;
        if(s[i]=='*')
            ans+=solve(s,i+1,n,dp)*9;
        else
            ans+=solve(s,i+1,n,dp);

        ans%=mod;
        string num=s.substr(i,2);
        if(num=="1*"){
            if(i==n-2)return dp[i]=(ans+9)%mod;
            ans+=solve(s,i+2,n,dp)*9;
        }
        else if(num=="2*"){
            if(i==n-2)return dp[i]=(ans+6)%mod;
            ans+=solve(s,i+2,n,dp)*6;
        }
        else if(num=="**"){
            if(i==n-2)return dp[i]=(ans+15)%mod;
            ans+=solve(s,i+2,n,dp)*15;
        }
        else if(num[1]=='*'){
        }
        else if(num[0]=='*'){
            if(num[1]<='6'){
                if(i==n-2)return dp[i]=(ans+2)%mod;
                ans+=solve(s,i+2,n,dp)*2;
            }
            else{
                if(i==n-2)return dp[i]=(ans+1)%mod;
                ans+=solve(s,i+2,n,dp);
            }
        }
        else if(num<="26"){
            if(i==n-2)return dp[i]=(ans+1)%mod;
            ans+=solve(s,i+2,n,dp);
        }
        ans%=mod;
        return dp[i]=ans;
    }
    int numDecodings(string s) {
        vector<long> dp(s.length()+1,-1);
        dp[s.length()]=0;
        return solve(s,0,s.length(),dp);
        
    }
};


