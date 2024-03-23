Q1: Find-First-And-Last-Position-of-Element.

sol:class Solution {
public:
    int small(vector<int>&arr,int target){
        int s=0;
        int e=arr.size()-1;
        int ans=-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(arr[mid]==target){
                ans=mid;
                e=mid-1;
            }
            else if(arr[mid]<target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return ans;
    }
    int large(vector<int>&arr,int target){
        int s=0;
        int e=arr.size()-1;
        int ans=-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(arr[mid]==target){
                ans=mid;
                s=mid+1;
            }
            else if(arr[mid]<target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {small(nums,target),large(nums,target)};

    }
};


Q2: Search -in-a-rotated-sorted-array.

sol:class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        int mid;
        while(s<=e){
             mid=(s+e)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>=nums[s]){
                if(nums[mid]>=target&& target>=nums[s]){
                    e=mid-1;
                }
                else{
                    s=mid+1;
                }
            }
            else{
                if(target>=nums[mid]&&target<=nums[e]){
                    s=mid+1;
                }
                else{
                    e=mid-1;
                }
            }

        }
        return -1;
    }
};


Q3: find-minimum-in-rotated-sorted-array.

sol: class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0;
        int h=nums.size()-1;
        int mini=nums[0];
        while(l<=h){
            int mid=(l+h)/2;
            mini=min(min(mini,nums[l]),nums[mid]);
            if(nums[mid]>=nums[l]){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return mini;
    }
};


Q4: find-rotation-count-rotated-sorted-array.

sol: #include<bits/stdc++.h>
using namespace std;
int countRotation(int arr[],int low,int high){
    if (high < low) 
        return 0; 
        
    if (high == low) 
        return low; 
  
    int mid = low + (high - low) / 2; 

    if (mid < high && arr[mid + 1] < arr[mid]) 
        return (mid + 1); 

    if (mid > low && arr[mid] < arr[mid - 1]) 
        return mid; 

    if (arr[high] > arr[mid]) 
        return countRotation(arr, low, mid - 1); 
  
    return countRotation(arr, mid + 1, high); 
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<countRotation(arr,0,n-1);
    return 0;
}


Q5: search-in-rotated-sorted-array-ii.

sol: class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int s=0;
        int e=n-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(nums[mid]==target){
                return true;
            }
            if(nums[s]==nums[mid] && nums[e]==nums[mid]){
                s++;
                e--;
                continue;
            }
            if(nums[s]<=nums[mid]){
                if(nums[s]<=target && target<nums[mid]){
                    e=mid-1;
                }
                else{
                    s=mid+1;
                }
            }
            else{
                if(target<=nums[e] && nums[mid]<target){
                    s=mid+1;
                }
                else{
                    e=mid-1;
                }
            }
            
        }
        return false;
    }
};