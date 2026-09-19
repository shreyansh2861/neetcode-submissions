class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=1,z=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                n*=nums[i];
            }
            else{
                z++;
            }
        }

        vector<int> ans(nums.size(),0);

        if(z>1){
            return ans;
        }

        for(int i=0;i<nums.size();i++){
            if(z>0){
                if(nums[i]==0){
                    ans[i]=n;
                }
            }
            else{
                ans[i]=n/nums[i];
            }
        }

        return ans;
    }
};
