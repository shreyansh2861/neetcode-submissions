class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int l, int r){
        while(l<=r){
            int m=(l+r)/2;
            if(nums[m]==target){
                return m;
            }
            if(nums[m]>target){
                r=m-1;
            }
            if(nums[m]<target){
                l=m+1;
            }
        }

        return -1;
    }
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;

        while(l<r){
            int m=(l+r)/2;
            if(nums[m]>nums[r]){
                l=m+1;
            }
            else{
                r=m;
            }
        }

        int pivot = l;
        int result = binarySearch(nums,target,pivot,nums.size()-1);
        if(result!=-1){
            return result;
        }

        return binarySearch(nums,target,0,pivot);
    }
};