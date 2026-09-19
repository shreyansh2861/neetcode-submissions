class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> temp(nums.size(),INT_MIN);
        return dfs(nums,temp,0);
    }

    int dfs(vector<int>& nums,vector<int>& temp, int i){
        if(i>=nums.size()){
            return 0;
        }
        if(temp[i]>INT_MIN){
            return temp[i];
        }
        temp[i] = max(nums[i]+dfs(nums,temp,i+2),dfs(nums,temp,i+1));
        return temp[i];
    }
};
