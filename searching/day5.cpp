Q: k-th-element-of-2-sorted-array.

int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
    int i=0;
    int j=0;
    int cnt=1;
    int ans=0;
    while(cnt<=k){
        if(arr1[i]<arr2[j]){
            if(cnt==k){
                ans=arr1[i];
            }
            i++;
            cnt++;
        }
        else{
            if(cnt==k){
                ans=arr2[j];
            }
            j++;
            cnt++;
        }
    }
    return ans;
}

Q: kth-element-in-matrix.

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  vector<int>vec;
  for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
          vec.push_back(mat[i][j]);
      }
  }
  sort(vec.begin(),vec.end());
  return vec[k-1];
}

Q: median-of-two-sorted-arrays

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int> nums(n+m);
        int index=0;
        int l=0;
        int r=0;
        while(l<n&&r<m){
            if(nums1[l]<=nums2[r]){
                nums[index++]=nums1[l++];
            }
            else{
                nums[index++]=nums2[r++];
            }
        }
        while(l<n){
            nums[index++]=nums1[l++];
        }
        while(r<m){
            nums[index++]=nums2[r++];
        }
        double ans;
        int mid=(n+m)/2;
        if((n+m)%2==0){
            ans=(nums[mid]+nums[mid-1])/2.0;
        }
        else{
            ans=nums[mid];
        }
        return ans;
    }
};

Q: search-a-2d-matrix

class Solution {
public:
    bool binarySearch(vector<int>& matrix ,int target){
        int low=0;
        int high=matrix.size();
        while(low<=high){
            int mid=low+(high-low)/2;
            if(matrix[mid]==target){
                return true;
            }
            else if(matrix[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            if(matrix[i][0]<=target && matrix[i][m-1]>=target){
                return binarySearch(matrix[i],target);
            }
        }
        return false;
    }
};

