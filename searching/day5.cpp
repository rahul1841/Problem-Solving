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


Q: kth_element_matrix

#include<bits/stdc++.h>
using namespace std;

int solve(int a[MAX][MAX], int n, int mid)
{
    int count = 0;
    int i = n - 1;
    int j = 0;

    while (i >= 0 && j < n)
    {
        if (a[i][j] <= mid){
            count += (i + 1);
            j++;
        }
        else i--;
    }
    return count;
}
int kthSmallest(int matrix[MAX][MAX], int n, int k)
{
    int low = matrix[0][0];
    int high = matrix[n - 1][n - 1];

    while (low < high){
        int mid = low + (high - low) / 2;
        int count = solve(matrix, n, mid);
        if (count < k) 
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}


Q: matrix_median

#include<bits/stdc++.h>
using namespace std;
int countless(vector<vector<int> > &A, int num)
{
int n = A.size();
int m = A[0].size();
int cnt=0;
for(int i=0;i<n;i++)
{
    int l=0,h=m-1;
    while(l<h)
    {
        int middle = (l+h)/2;
        if(A[i][middle] <= num)
            l=middle+1;
        else if(A[i][middle] > num)
            h=middle;
    }
    if(A[i][l] <= num)
        cnt+=l+1;
    else
        cnt+=l;
}
return cnt;
}
int findMedian(vector<vector<int>> &A)
{
  int low = INT_MAX;
  int high = INT_MIN;
  int n = A.size();
  int m = A[0].size();
  int k=(n*m)/2;
  for(int i=0;i<n;i++){

    low=min(low, A[i][0]);
    high= max(high, A[i][m-1]);
  }

  while (low <= high)
  {
    int mid = (low + high) >> 1;
    int cnt = countless(A,mid);
    if(cnt >= (k+1))
        high=mid-1;
    else if(cnt < (k+1))
        low=mid+1;
  }
  return low;
}