Q1: Aggressive-cows.

sol: class Solution {
public:
    bool isPossible(int numStalls, int numCows, vector<int> &stalls,int minDist){
        int lastPlacedCow=stalls[0];
        int totalCowPlaced=1;
        for(int i=1;i<numStalls;i++){
            if(stalls[i]-lastPlacedCow>=minDist){
                totalCowPlaced++;
                lastPlacedCow=stalls[i];
            }
        }
        return totalCowPlaced>=numCows;
    }
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
        int low=1;
        int high=stalls[n-1]-stalls[0]+1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(n,k,stalls,mid)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};


Q2: find-nth-root.

sol: class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    int low=1;
	    int high=m;
	    while(low<=high){
	        int mid=low+(high-low)/2;
	        if(pow(mid,n)==m){ 
	            return mid;
	        }
	        else if(pow(mid,n)>m){ 
	            high=mid-1;
	        }
	        else{
	            low=mid+1;
	        }
	    }
	    return -1;
	}  
};


Q3: find-peak-element.

sol:class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;
        int low=1;
        int high=n-2;
        while(low<=high){
            int mid= low+(high-low)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(nums[mid]>nums[mid-1]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return -1;
    }
};


Q4: single-element-in-a-sorted-array.

sol: class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];
        int low=1;
        int high=n-2;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
                return nums[mid];
            }
            if(mid%2==1){
                if(nums[mid]==nums[mid-1]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
            else{
                if(nums[mid]==nums[mid+1]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return -1;
    }
};


Q5: sqrtx.

sol: class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return x;
        int low=1;
        int high=x;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mid==x/mid) {
                return mid;
            }
            else if(mid>x/mid) {
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return high;
    }
};