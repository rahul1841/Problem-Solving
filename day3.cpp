Q1: minimum-limit-of-balls-in-a-bag

class Solution {
public:
    bool isPossible(vector<int>& nums, int mid,int maxOperations){
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%mid==0){
                cnt+=(nums[i]/mid)-1;
            }
            else{
                cnt+=(nums[i]/mid);
            }
            if(cnt > maxOperations){
                return false;
            }
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int start=1;
        int end=INT_MIN;
        for(int i=0;i<nums.size();i++){
            end=max(end,nums[i]);
        }
        int ans=0;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(isPossible(nums,mid,maxOperations)){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};


Q2: minimum-number-of-days-to-make-m-bouquets

class Solution {
public:
    bool isPossible(vector<int>& bloomDay,int m,int k,int mid){
        int cnt=0;
        int totalcnt=0;
        int n=bloomDay.size();
        for(int i=0;i<n;i++){
            if(mid>=bloomDay[i]){
                cnt++;
                if(cnt==k){
                    totalcnt++;
                    cnt=0;
                }
            }
            else{
                cnt=0;
            }
        }
        return totalcnt>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(m>n/k) return -1;

        int low=1;
        int high=INT_MIN;
        for(int i=0;i<n;i++){
            high=max(high,bloomDay[i]);
        } 
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(bloomDay,m,k,mid)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};

Q3: painter-s-partition-problem

bool isPossible(vector<int>boards,int n,int k,int mid){
    int painters=1;
    int boardsum=0;
    for(int i=0;i<n;i++){
        if(boards[i]+boardsum<=mid){
            boardsum+=boards[i];
        }
        else{
            painters++;
            if(painters>k || boards[i]>mid){
                return false;
            }
            boardsum=boards[i];
        }
    }
    return true;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    int low=0;
    int sum=0;
    int n=boards.size();
    for(int i=0;i<n;i++){
        sum+=boards[i];
    }
    int high=sum;
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(isPossible(boards,n,k,mid)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}